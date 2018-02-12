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


void		calc_wp_num(t_flag_list *t_fl, long size, int is_sign)
{
	char	sign;

	sign = 0;
	//---------------define c_sign si nb sign----------
	if (is_sign)
	{
		if (t_fl->neg)
			t_fl->c_sign = '-';
		else if (t_fl->space && !t_fl->plus)
			t_fl->c_sign = ' ';
		else
			t_fl->c_sign = '+';
	}
	//--------------------------------------
	//---------------define c_width---------
	if (t_fl->zero && !t_fl->min && !t_fl->prec)
		t_fl->c_width = '0';
	//--------------------------------------
	// print_tfl(*t_fl);
	//---------define prec----------
	if ((t_fl->prec -= size) < 0)
		t_fl->prec = 0;
	//---------define sign----------
	if (is_sign && (t_fl->plus || t_fl->space || t_fl->neg))
		{
			t_fl->width--;
			sign = 1;
		}
	//---------define width----------
	if ((t_fl->width -= (t_fl->prec + size)) < 0)
		t_fl->width = 0;
	//---------define field----------
	// print_tfl(*t_fl);
	t_fl->field = t_fl->width + t_fl->prec + size + sign;
	// print_tfl(*t_fl);
}

void		calc_wp_str(t_flag_list *t_fl, int size)
{
	// print_tfl(*t_fl);
	//---------------define c_width---------
	if (t_fl->zero && !t_fl->min)
		t_fl->c_width = '0';
	//--------------------------------------
	//--------pour rien print si precision nul
	if (!t_fl->put_val)
		size = 0;
	//---------define prec----------
	if (!t_fl->prec || t_fl->prec > size)
		t_fl->prec = size;
	//---------define width----------
	if ((t_fl->width -= t_fl->prec) < 0)
		t_fl->width = 0;
	//---------define field----------
	t_fl->field = t_fl->width + t_fl->prec;
}

void		calc_wp_num_base(t_flag_list *t_fl, long size, int sharp)
{
	//--------------------------------------
	//---------------define c_width---------
	if (t_fl->zero && !t_fl->min && !t_fl->prec)
		t_fl->c_width = '0';
	//--------------------------------------
	// print_tfl(*t_fl);
	// printf("size = %li\n", size);
	// printf("size = %li\n", size + t_fl->prec);
	//---------define prec----------
	if ((t_fl->prec -= size) < 0)
		t_fl->prec = 0;
	//---------define width----------
	if ((t_fl->width -= (t_fl->prec + size + sharp)) < 0)
		t_fl->width = 0;
	//---------define field----------
	t_fl->field = t_fl->width + t_fl->prec + size + sharp;
	// print_tfl(*t_fl);
}
