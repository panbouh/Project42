#include "ft_printf.h"
#include "ft_wuni.h"

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
	char	exeptab[NB_FLAG + 1] = ALL_FLAG;

	i = 0;
	if (ft_isalpha(c))
		return (1);

	while (exeptab[i])
		if (ft_isdigit(c) || c == exeptab[i++])
			return (0);
	return (1);
}

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

	while (str[i] && (is_mod(str[i])))
		(i)++;
	tmp = ft_strsub(str, (unsigned int)save_i, i - save_i);
	mod = ft_strtrim_full(tmp);
	ft_strdel(&tmp);
	return (mod);
}