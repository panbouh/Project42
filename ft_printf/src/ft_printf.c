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

t_flag	g_flagtab[] =
{
	{'#', &flag_sharp},
	{'0', &flag_zero},
	{'-', &flag_min},
	{'+', &flag_plus},
	{0, NULL},
};

t_conv	g_convtab[] =
{
	{'i', &conv_int},
	{'d', &conv_int},
	{'s', &conv_str},
	{'c', &conv_char},
	{'u', &conv_unsigned},
	{'x', &conv_hexa},
	{'X', &conv_hexaup},
	{'b', &conv_bina},
	{'o', &conv_octa},
	{'p', &conv_hexa},
	{0, NULL},
};

t_mod	g_modtab[] =
{
	{"l", &conv_mod_l},
	{"ll", &conv_mod_ll},
	{"h", &conv_mod_h},
	{"hh", &conv_mod_h},
	{"j", &conv_mod_j},
	{"z", &conv_mod_z},
	{NULL, NULL},
};
/*
		[flags]			#0-+
		[largeur]		N
		[precision]		.N
		[conversion]	sSpdDioOuUxXcC (hh h ll l j z)
*/

void	ion_ft(const char *form, size_t *i, t_flag_list *t_fl)
{
	size_t	nb_f;

	nb_f = 0;
	while (g_flagtab[nb_f].key)
	{
		if (g_flagtab[nb_f++].key == form[*i])
		{
			g_flagtab[nb_f - 1].f(t_fl);
			(*i)++;
			nb_f = 0;
		}
	}
}

int	do_conv(const char *form, size_t *i, t_flag_list t_fl, va_list ap)
{
	size_t	n;
	size_t	size;

	n = 0;
	while (g_convtab[n].key)
	{
		if (g_convtab[n].key == form[*i])
			{
				(*i)++;;
				g_convtab[n].f(ap, t_fl);
				return (OK);
			}
		size = ft_strlen(g_modtab[n].key);
		if (!ft_strncmp(g_modtab[n].key, &form[*i], size))
			{
				(*i) += size;
				g_modtab[n].f(ap, t_fl, form[*i]);
				return (OK);
			}
		n++;
	}
	if (ft_isalpha(form[*i]))
			return (conv_nothing(t_fl, form[(*i)++]));
	return (FAIL);
}

int	found_flags(const char *form, va_list ap, size_t *i)
{
	t_flag_list	t_fl;
	char	ret_end;

	(*i)++;
	t_fl = init_fl();
	*i = ft_skip_char(form, *i, ' ', ALL);

	while ((ret_end = do_conv(form, i, t_fl, ap)) != OK && ret_end != FAIL)
	{
		SKIP_SPACE
		ion_ft(form, i, &t_fl);
		SKIP_SPACE
		if (ft_isdigit(form[*i]))
			if ((t_fl.width = ft_atoi(&form[*i])))
				*i += ft_count_digit(t_fl.width);
		SKIP_SPACE
		if (form[*i] == '.')
		{
			(*i)++;
			t_fl.prec = ft_atoi(&form[*i]);
			*i += ft_count_digit(t_fl.prec);
		}
		SKIP_SPACE
	}
	if (ret_end == OK)
		return (OK);
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
		if (format[i] == '%' && format[i + 1] && format[i + 1] != '%')
		{
			if (found_flags(format, ap, &i) == FAIL)
			{
				return (ret_err());
			}
		}
		if (format[i + 1] && format[i + 1] == '%')
			i++;
		ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (OK);
}