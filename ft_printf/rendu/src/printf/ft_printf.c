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
**	[flags]			# 0-+
**	[largeur]		N
**	[precision]		.N
**	[conversion]	sSpdDioOuUxXcCb (hh h ll l j z)
*/

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
	{'i', &conv_id},
	{'d', &conv_id},
	{'D', &conv_lid},
	{'s', &conv_s},
	{'S', &conv_ls},
	{'c', &conv_c},
	{'C', &conv_lc},
	{'u', &conv_u},
	{'U', &conv_lu},
	{'x', &conv_x},
	{'X', &conv_xm},
	{'b', &conv_b},
	{'o', &conv_o},
	{'O', &conv_lo},
	{'p', &conv_p},
	{0, NULL},
};

t_mod	g_modtab[] =
{
	{"l", &conv_mod_l},
	{"ll", &conv_mod_ll},
	{"h", &conv_mod_h},
	{"hh", &conv_mod_hh},
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

void	check_for_pw(const char *form, size_t *i, t_flag_list *t_fl)
{
	size_t	size;

	size = 1;
	if (form[*i] == '.')
	{
		t_fl->prec = ft_atoi(&form[*i + 1]);
		if (t_fl->prec == 0)
		{
			t_fl->put_val = 0;
			if (form[*i  + 1] == '0')
				size++;
		}
		else
			size += ft_count_digit(t_fl->prec);
		*i += size;
	}
	if (ft_isdigit(form[*i]) && form[*i] != '0')
	{
		t_fl->width = ft_atoi(&form[*i]);
		*i += ft_count_digit(t_fl->width);
	}
}

int		do_conv(const char *form, va_list ap, size_t *i, t_flag_list *t_fl) //nbligne 27
{
	char	*mod;
	size_t	y;
	int		ret;

	y = 0;
	while (g_convtab[y].key)
	{
		if (g_convtab[y].key == form[*i])
			return (g_convtab[y].f(ap, *t_fl));
		y++;
	}
	y = 0;
	if (!(mod = get_mod(form, *i)))
		return (FAIL);
	while (g_modtab[y].key)
	{
		if (!(ft_strcmp(g_modtab[y].key, mod)))
		{
			ret = g_modtab[y].f(ap, *t_fl, form, i);
			ft_strdel(&mod);
			return (ret);
		}
		y++;
	}
	*i += ft_strlen(mod);
	ft_strdel(&mod);
	return (FAIL);
}

int		found_flag(const char *form, va_list ap, size_t *i)
{
	char		status;
	t_flag_list	t_fl;
	int			ret;

	status = GO;
	t_fl = init_fl();
	(*i)++;
	ret = 0;//utile?
	while (status != STOP && form[*i])
	{
		if (is_conv(form[*i]))
		{
			if (((ret = do_conv(form, ap, i, &t_fl)) != FAIL))
				return (ret);
			status = STOP;
		}
		check_for_pw(form, i, &t_fl);
		*i += check_for_flag(form[*i], &t_fl);
	}
	if (!form[*i])
		return (FAIL);
	return (conv_nothing(t_fl, form[*i]));
}

int		ft_printf(const char *format, ...) //nbligne 28
{
	va_list	ap;
	size_t	i;
	int		ret_end;
	int		ret;
	int		count;

	i = 0;
	ret = 0;
	ret_end = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((ret = found_flag(format, ap, &i)) == FAIL || !format[i])
				return (ret_end + count);
			ret_end += ret;
			i++;
		}
		else
		{
			ft_putchar(format[i++]);
			count++;
		}
	}
	va_end(ap);
	return (ret_end + count);
}