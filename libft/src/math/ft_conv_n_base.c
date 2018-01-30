#include "libft.h"

char	*ft_conv_nbase(int n, unsigned int base)
{
	char	conv[123456];
	int		n_tmp;
	int		rest;
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base > 36)
		return (NULL);
	ft_bzero(conv, 123456);
	while (n > 0 && i < 123456)
	{
		n_tmp = n;
		n /= base;
		if ((rest = n_tmp % base) < 10)
			conv[i] = rest + 48;
		else
			conv[i] = 'a' + ft_abs(rest - 10);
		i++;
	}
	conv[i] = 0;
	return (ft_strrev(ft_strdup(conv)));
}

char	*ft_convu_nbase(unsigned int n, unsigned int base)
{
	char				conv[123456];
	unsigned int		n_tmp;
	int					rest;
	size_t				i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base > 36)
		return (NULL);
	ft_bzero(conv, 123456);
	while (n > 0 && i < 123456)
	{
		n_tmp = n;
		n /= base;
		if ((rest = n_tmp % base) < 10)
			conv[i] = rest + 48;
		else
			conv[i] = 'a' + ft_abs(rest - 10);
		i++;
	}
	conv[i] = 0;
	return (ft_strrev(ft_strdup(conv)));
}

char	*ft_convlu_nbase(unsigned long long n, unsigned int base)
{
	char					conv[123456];
	unsigned long long		n_tmp;
	int						rest;
	size_t					i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base > 36)
		return (NULL);
	ft_bzero(conv, 123456);
	while (n > 0 && i < 123456)
	{
		n_tmp = n;
		n /= base;
		if ((rest = n_tmp % base) < 10)
			conv[i] = rest + 48;
		else
			conv[i] = 'a' + ft_abs(rest - 10);
		i++;
	}
	conv[i] = 0;
	return (ft_strrev(ft_strdup(conv)));
}

char	*ft_convumax_nbase(uintmax_t n, unsigned int base)
{
	char		conv[123456];
	uintmax_t	n_tmp;
	int			rest;
	size_t		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base > 36)
		return (NULL);
	ft_bzero(conv, 123456);
	while (n > 0 && i < 123456)
	{
		n_tmp = n;
		n /= base;
		if ((rest = n_tmp % base) < 10)
			conv[i] = rest + 48;
		else
			conv[i] = 'a' + ft_abs(rest - 10);
		i++;
	}
	conv[i] = 0;
	return (ft_strrev(ft_strdup(conv)));
}

char	*ft_convimax_nbase(intmax_t n, unsigned int base)
{
	char		conv[123456];
	intmax_t	n_tmp;
	int			rest;
	size_t		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base > 36)
		return (NULL);
	ft_bzero(conv, 123456);
	while (n > 0 && i < 123456)
	{
		n_tmp = n;
		n /= base;
		if ((rest = n_tmp % base) < 10)
			conv[i] = rest + 48;
		else
			conv[i] = 'a' + ft_abs(rest - 10);
		i++;
	}
	conv[i] = 0;
	return (ft_strrev(ft_strdup(conv)));
}