/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:58:15 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/16 14:58:15 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	// printf("\n1) w = %i, p = %i\n", t_fl.width, t_fl.prec);
	// printf("flag = %i\n", t_fl.space);


int	conv_unsigned(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
	size_t			size;

	nb = va_arg(ap, unsigned int);
	size = ft_count_digit(nb);
	calc_wp_num(&t_fl, size);
	if (t_fl.zero && !t_fl.min && !t_fl.prec)
		t_fl.c_width = '0';
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_putnchar('0', t_fl.prec);
	ft_putunbr(nb);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (size + (t_fl.width + t_fl.prec));
}

int	conv_int(va_list ap, t_flag_list t_fl)
{
	int			nb;
	size_t		size;

	nb = va_arg(ap, int);
	size = 0;
	if (nb)
		size = ft_count_digit(ft_abs(nb));
	calc_wp_num(&t_fl, size);
	if (nb < 0)
	{
		t_fl.c_sign = '-';
		t_fl.plus = 0;
	}
	else if (t_fl.space && !t_fl.plus)
		t_fl.c_sign = ' ';
	else
		t_fl.c_sign = '+';
	if (t_fl.zero && !t_fl.min && !t_fl.prec)
		t_fl.c_width = '0';
	if (t_fl.width > 0 && (t_fl.plus || t_fl.space || nb < 0))
		t_fl.width--;
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.plus || t_fl.space || nb < 0)
	{
		size++;
		ft_putchar(t_fl.c_sign);
	}
	if (t_fl.prec > 0)
		ft_putnchar('0', t_fl.prec);
	if (t_fl.prec >= 0)
		ft_putunbr(ft_abs(nb));
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (size + (t_fl.width + t_fl.prec));
}

// t_fl->width - t_fl->prec - size - t_fl->plus

int	conv_str(va_list ap, t_flag_list t_fl)
{
	char	*str;
	size_t	size;

	str = va_arg(ap, char *);
	size = ft_strlen(str);
	// printf("\nwitdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	calc_wp_str(&t_fl, size);

	// printf("min = %i\n", t_fl.min);
	// printf("witdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);

	if (str)
		ft_putnofstr(str, t_fl.prec);
	else
	{
		t_fl.prec = 6;
		ft_putstr("(null)");
	}


	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	// printf("ret 2= %i\n", t_fl.width + t_fl.prec);
	return (t_fl.width + t_fl.prec);
}

int	conv_char(va_list ap, t_flag_list t_fl)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	(void)t_fl;
	ft_putchar(c);
	return (1);
}

int	conv_sizet(va_list ap, t_flag_list t_fl)
{
	return (0);
}
