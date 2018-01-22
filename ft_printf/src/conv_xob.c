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

int		conv_hexa(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
	char			*conv;
	
	nb = va_arg(ap, unsigned int);
	conv = ft_conv_n_base(nb, 16);

	calc_wp_num(&t_fl, ft_strlen(conv));

	// printf("min = %i\n", t_fl.min);
	// printf("witdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	if (t_fl.sharp)
		if ((t_fl.width -= 2) < 0)
			t_fl.width = 0;
	
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);

	if (t_fl.sharp)
		ft_putstr("0x");

	ft_putnchar('0', t_fl.prec);

	ft_putstr(conv);

	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_strdel(&conv);
}

int		conv_hexaup(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
	char			*conv;
	
	nb = va_arg(ap, unsigned int);
	conv = ft_conv_n_base(nb, 16);

	calc_wp_num(&t_fl, ft_strlen(conv));

	// printf("min = %i\n", t_fl.min);
	// printf("witdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	if (t_fl.sharp)
		if ((t_fl.width -= 2) < 0)
			t_fl.width = 0;
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);

	if (t_fl.sharp)
		ft_putstr("0x");

	ft_putnchar('0', t_fl.prec);

	ft_putstr(ft_strupper(conv));

	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_strdel(&conv);
}

int		conv_octa(va_list ap, t_flag_list t_fl)
{
		unsigned int	nb;
	char			*conv;
	
	nb = va_arg(ap, unsigned int);
	conv = ft_conv_n_base(nb, 8);

	calc_wp_num(&t_fl, ft_strlen(conv));

	// printf("min = %i\n", t_fl.min);
	// printf("witdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	if (t_fl.sharp)
		if ((t_fl.prec -= 1) < 0)
			t_fl.prec = 0;

	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);

	if (t_fl.sharp)
		ft_putchar('0');


	ft_putnchar('0', t_fl.prec);

	ft_putstr(conv);

	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_strdel(&conv);
}

int		conv_bina(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
	char			*conv;

	nb = va_arg(ap, unsigned int);
	conv = ft_conv_n_base(nb, 2);

	calc_wp_num(&t_fl, ft_strlen(conv));

	// printf("min = %i\n", t_fl.min);
	// printf("witdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);

	ft_putnchar('0', t_fl.prec);

	ft_putstr(conv);

	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_strdel(&conv);
}
