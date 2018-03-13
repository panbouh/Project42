#include "libft.h"

char	**ft_tabcpy(char **src, char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		src[i] = dest[i];
		i++;
	}
	return (dest);
}

void	ft_tabdel(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_memdel(&tab[i]);
		i++;
	}
	ft_memdel(tab);
}

void	ft_memswap(void **a, void **b)
{
	void	*save;

	save = *a;
	*a = *b;
	*b = save;
}

void	**ft_tabdup(void **src)
{
	void	**new;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	new = malloc(sizeof(src) * size + 1);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = NULL;
	return (new);
}