#include "libft.h"

static void	init_tab(char	*tab, size_t size)
{
	unsigned int	u;

	u = 0;
	while (u < size)
		tab[u++] = 0;
}

char	*ft_conv_n_base(int n, unsigned int base)
{
	char	conv[123456];
	int		n_tmp;
	int		rest;
	size_t	i;

	i = 0;

	if (base > 36)
		return (NULL);
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
	return (ft_strrev(ft_strdup(conv)));
}