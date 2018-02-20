/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_conv_chiante.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:22 by ccatoire          #+#    #+#             */
/*   Updated: 2018/01/15 16:04:23 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_u(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
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

int	conv_id(va_list ap, t_flag_list t_fl)
{
	int			nb;
	size_t		size;

	nb = va_arg(ap, int);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_count_udigit(ft_abs(nb));
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
		ft_putunbr(ft_abs(nb));
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_s(va_list ap, t_flag_list t_fl)
{
	char	*str;
	size_t	size;

	str = va_arg(ap, char *);
	if (!str)
	{
		t_fl.neg = 1;
		str = ft_strdup("(null)");
	}
	size = ft_strlen(str);
	calc_wp_str(&t_fl, size);
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (str && t_fl.put_val)
		ft_putnofstr(str, t_fl.prec);
	else if (!str)
		ft_putstr("(null)");
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.neg)
		ft_strdel(&str);
	return (t_fl.field);
}

int	conv_c(va_list ap, t_flag_list t_fl)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	if ((t_fl.width -= 1) < 0)
		t_fl.width = 0;
	t_fl.field = t_fl.width + 1;
	if (t_fl.zero)
		t_fl.c_width = '0';
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_putchar(c);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_zu(va_list ap, t_flag_list t_fl)
{
	size_t	nb;
	size_t	size;

	nb = va_arg(ap, size_t);
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
