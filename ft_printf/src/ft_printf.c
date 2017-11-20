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

t_bouh	g_bouhtab[] = {
	{'i', &flag_int},	\
	{'d', &flag_int},	\
	{'s', &flag_str},	\
	{'c', &flag_char},
};

int	ret_err()
{
	ft_putendl_fd("<ERROR parsing ERROR>", 2);
	return (FAIL);
}

int	found_flags(char flag, va_list ap)
{
	size_t	i;

	i = 0;
	while (i < FLAG_NB)
	{
		if (g_bouhtab[i].key == flag)
			{
				g_bouhtab[i].f(ap);
				return (OK);
			}
		i++;
	}
	return (FAIL);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;

	i = 0;
	if (!format)
		return (FAIL);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] != '%')
				{

					if (found_flags(format[i + 1], ap) == FAIL)
						return (ret_err());
					i++;
				}
			i++;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (OK);
}