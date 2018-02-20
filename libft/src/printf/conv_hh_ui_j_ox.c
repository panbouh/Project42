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

/*
** hhu hhi/d
*/

int	conv_hhu(va_list ap, t_flag_list t_fl)
{
	unsigned char	nb;
	size_t			size;

	nb = va_arg(ap, unsigned int);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_count_udigit(nb);
	calc_wp_num(&t_fl, size, 0);
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_putnchar('0', t_fl.prec);
	if (t_fl.put_val || nb)
		ft_putunbr(nb);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_hhid(va_list ap, t_flag_list t_fl)
{
	char	nb;
	size_t	size;

	nb = va_arg(ap, int);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_count_digit(ft_abs(nb));
	if (nb < 0)
		t_fl.neg = 1;
	calc_wp_num(&t_fl, size, 1);
	if (!t_fl.min && !t_fl.zero)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.plus || t_fl.space || t_fl.neg)
		ft_putchar(t_fl.c_sign);
	if (!t_fl.min && t_fl.zero)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_putnchar('0', t_fl.prec);
	if (t_fl.put_val || nb)
		ft_putnbr(ft_abs(nb));
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

/*
** jo jx jX
*/

int	conv_jo(va_list ap, t_flag_list t_fl)
{
	uintmax_t	nb;
	char		*conv;
	size_t		size;

	nb = va_arg(ap, uintmax_t);
	conv = ft_convumax_nbase(nb, 8);
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

int	conv_jx(va_list ap, t_flag_list t_fl)
{
	uintmax_t	nb;
	char		*conv;
	size_t		size;

	nb = va_arg(ap, uintmax_t);
	conv = ft_convumax_nbase(nb, 16);
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

int	conv_jxm(va_list ap, t_flag_list t_fl)
{
	uintmax_t	nb;
	char		*conv;
	size_t		size;

	nb = va_arg(ap, uintmax_t);
	conv = ft_convumax_nbase(nb, 16);
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
