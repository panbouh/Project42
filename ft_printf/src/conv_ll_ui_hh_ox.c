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

/*
** llu lli
*/

int	conv_ullongint(va_list ap, t_flag_list t_fl)
{
	int i;

	i = 0;
	while (i < 9)
		i++;
	printf("%i\n", i);
}

int	conv_llong(va_list ap, t_flag_list t_fl)
{
	int i;

	i = 0;
	while (i < 9)
		i++;
	printf("%i\n", i);

}

/*
** hho hhx hhX
*/

int	conv_ucharocta(va_list ap, t_flag_list t_fl)
{
	int i;

	i = 0;
	while (i < 9)
		i++;
	printf("%i\n", i);

}

int	conv_ucharhexa(va_list ap, t_flag_list t_fl)
{
	int i;

	i = 0;
	while (i < 9)
		i++;
	printf("%i\n", i);

}

int	conv_ucharhexaup(va_list ap, t_flag_list t_fl)
{
	int i;

	i = 0;
	while (i < 9)
		i++;
	printf("%i\n", i);

}