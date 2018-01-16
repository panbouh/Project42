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

t_flag	g_flagtab[] =
{
	{'#', &flag_sharp},
	{'0', &flag_zero},
	{'-', &flag_min},
	{'+', &flag_plus},
	{' ', &flag_space},
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

int		check_for_flag(char c, t_flag_list *t_fl)
{
	size_t	i;

	i = 0;
	while (g_flagtab[i].key)
	{
		if (g_flagtab[i].key == c)
		{
			g_flagtab[i].f(t_fl);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_for_pw(const char *form, size_t *y, t_flag_list *t_fl)
{
	size_t	i;

	i = *y;
	if (form[i] == '.')
	{
		t_fl->prec = ft_atoi(&form[i + 1]);
		i += ft_count_digit(t_fl->prec);
	}
	if (ft_isdigit(form[i]))
	{
		t_fl->width = ft_atoi(&form[i]);
		i += ft_count_digit(t_fl->width);
	}
	*y = i;
}

int		do_conv(const char *form, va_list ap, size_t *i, t_flag_list *t_fl)
{
	size_t	y;
	size_t	size;

	y = 0;
	while (g_convtab[y].key)
		if (g_convtab[y].key == form[*i])
			return (g_convtab[y].f(ap, *t_fl));
	y = 0;
	while (g_modtab[y].key)
	{
		size = ft_strlen(g_modtab[y].key);
		if (!(ft_strncmp(g_modtab[y].key, &form[*i], size)))
			return (g_modtab[y].f(ap, *t_fl, form[*i + size]));
	}
	return (0);
}

int		found_flag(const char *form, va_list ap, size_t *i)
{
	char	status;
	t_flag_list t_fl;
	int		ret;

	status = GO;
	t_fl = init_fl();
	while (status != STOP)
	{
		if (ft_isalpha(form[*i]))
		{
			if ((ret = do_conv(form, ap, i, &t_fl)))
				return (ret);
			status = STOP;
		}
		check_for_pw(form, i, &t_fl);
		*i += check_for_flag(form[*i], &t_fl);
	}
	return (conv_nothing(t_fl, form[*i]));
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += found_flag(format, ap, &i);
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (ret + i);
}