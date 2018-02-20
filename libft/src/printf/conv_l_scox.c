/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:31 by ccatoire          #+#    #+#             */
/*   Updated: 2018/01/16 16:58:31 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_wuni.h"

/*
**  ls lc lo lx lX
*/

int	conv_ls(va_list ap, t_flag_list t_fl)
{
	wchar_t	*wstr;
	size_t	size;

	wstr = va_arg(ap, wchar_t *);
	if (!wstr)
	{
		t_fl.neg = 1;
		wstr = ft_wstrdup(L"(null)");
	}
	size = nb_bit_print(wstr, t_fl.prec);
	calc_wp_str(&t_fl, size);
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (wstr && t_fl.put_val)
		ft_putnbyte(wstr, t_fl.prec);
	else if (t_fl.neg)
		ft_putstr("(null)");
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.neg)
		ft_wstrdel(&wstr);
	return (t_fl.field);
}

int	conv_lc(va_list ap, t_flag_list t_fl)
{
	wint_t	c;
	size_t	size;

	c = va_arg(ap, wint_t);
	if (!(size = ft_wcharlen(c)))
		size = 1;
	if ((t_fl.width -= size) < 0)
		t_fl.width = 0;
	t_fl.field = t_fl.width + size;
	if (t_fl.zero)
		t_fl.c_width = '0';
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_putwchar(c);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_lo(va_list ap, t_flag_list t_fl)
{
	unsigned long	nb;
	char			*conv;
	size_t			size;

	nb = va_arg(ap, unsigned long);
	conv = ft_convlu_nbase(nb, 8);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!((t_fl.sharp && nb) || (t_fl.sharp && !t_fl.put_val)))
		t_fl.sharp = 0;
	calc_wp_num_base(&t_fl, size + t_fl.sharp, 0);
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_putnchar('0', t_fl.prec);
	if ((t_fl.sharp && nb) || (t_fl.sharp && !t_fl.put_val))
		ft_putchar('0');
	if (t_fl.put_val || nb)
		ft_putstr(conv);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_strdel(&conv);
	return (t_fl.field);
}

int	conv_lx(va_list ap, t_flag_list t_fl)
{
	unsigned long	nb;
	char			*conv;
	size_t			size;

	nb = va_arg(ap, unsigned long);
	conv = ft_convlu_nbase(nb, 16);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!nb)
		t_fl.sharp = 0;
	calc_wp_num_base(&t_fl, size, (t_fl.sharp * 2));
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.sharp && (nb || t_fl.put_val))
		ft_putstr("0x");
	ft_putnchar('0', t_fl.prec);
	if (t_fl.put_val || nb)
		ft_putstr(conv);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_strdel(&conv);
	return (t_fl.field);
}

int	conv_lxm(va_list ap, t_flag_list t_fl)
{
	unsigned long	nb;
	char			*conv;
	size_t			size;

	nb = va_arg(ap, unsigned long);
	conv = ft_convlu_nbase(nb, 16);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!nb)
		t_fl.sharp = 0;
	calc_wp_num_base(&t_fl, size, (t_fl.sharp * 2));
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.sharp && (nb || t_fl.put_val))
		ft_putstr("0X");
	ft_putnchar('0', t_fl.prec);
	if (t_fl.put_val || nb)
		ft_putstr(ft_strupper(conv));
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_strdel(&conv);
	return (t_fl.field);
}
