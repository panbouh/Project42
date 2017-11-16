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

#include "printf.h"

void	found_flags(va_list ap, char flag)
{
	size_t	i;

	i = 0;
	while (i < FLAG_NB)
	{
		if (g_bouhtab[i].key == flag)
			g_bouhtab[i].f(ap);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '#')
		{
			found_flags(va_arg(ap), format[i + 1]);
			i += 2;
		}
		i++;
	}
	va_end(ap);
}