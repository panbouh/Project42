#include "ft_printf.h"


int		is_conv(char c)
{
	int		i;
	char	exeptab[NB_FLAG + 1] = ALL_FLAG;

	i = 0;
	if (ft_isalpha(c))
		return (1);

	while (exeptab[i])
		if (ft_isdigit(c) || c == exeptab[i++])
			return (0);
	return (1);
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

	while (!is_conv(str[i]) || str[i] == 'l' || str[i] == 'h' ||
		str[i] == 'z' || str[i] == 'j')
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