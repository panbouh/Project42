#include "ft_printf.h"
#include "ft_wuni.h"

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

int	ntmnorm(const char *form, va_list ap, size_t *i, t_flag_list *t_fl)
{
	char	*mod;
	size_t	y;
	int		ret;

	y = 0;
	if (!(mod = get_mod(form, *i)))
		return (FAIL);
	// printf("mod = <%s>\n", mod);
	while (g_modtab[y].key)
	{
		// printf("g_modtab[y].key = %s\n", g_modtab[y].key);
		if (!(ft_strcmp(g_modtab[y].key, mod)))
		{
			ret = g_modtab[y].f(ap, *t_fl, form, i);
			// printf("apres : form[i] = %c, i = %zu\n", form[*i], *i);
			ft_strdel(&mod);
			return (ret);
		}
		y++;
	}
	*i += ft_strlen(mod);
	ft_strdel(&mod);
	return (FAIL);
}

int		nb_bit_print(const wchar_t *wstr, size_t n)
{
	size_t	i;
	size_t	size;
	int		ret;
	int		stop;

	i = 0;
	ret = 0;
	stop = 0;
	size = ft_wstrlen(wstr);
	if (!n)
		return (size);
	if (n > size)
		n = size;
	while(wstr[i])
	{
		if ((stop += ft_wcharlen(wstr[i])) > n)
			return (ret);
		ret += stop;
		i++;
	}
	return (ret);
}

int		is_conv(char c)
{
	int		i;

	i = 0;
	if (ft_isalpha(c))
		return (1);

	while (ALL_FLAG[i])
		if (ft_isdigit(c) || c == ALL_FLAG[i++])
			return (0);
	return (1);
}

// int		is_conv(char c)
// {
// 	int		i;
// 	char	exeptab[NB_FLAG + 1] = ALL_FLAG; //lol

// 	i = 0;
// 	if (ft_isalpha(c))
// 		return (1);

// 	while (exeptab[i])
// 		if (ft_isdigit(c) || c == exeptab[i++])
// 			return (0);
// 	return (1);
// }

static int		is_mod(char c)
{
	if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (1);
	return (0);
}

char	*get_mod(const char *str, size_t i)
{
	size_t	save_i;
	char	save_c;
	char	*mod;
	char	*tmp;

	save_i = i;
	save_c = str[i];
	// printf("tmp = <%c>\n", str[i]);
	// printf("i = <%lu>\n", i);

	while (str[i] && (is_mod(str[i])))
		(i)++;
	// printf("i = <%lu>\n", i);
	// printf("tmp = <%c>\n", str[i - 1]);
	// printf("save_i = %lu, i = %lu, i - save_i = %lu\n", save_i, i, i - save_i);
	tmp = ft_strsub(str, (unsigned int)save_i, i - save_i);
	// printf("tmp = <%s>\n", tmp);
	mod = ft_strtrim_full(tmp);
	ft_strdel(&tmp);
	return (mod);
}