#include "libft.h"

char	**ft_tabschr(char **tab, const char *to_find)
{
	size_t	i;

	i = 0;

	while (tab[i] && ft_strstr(tab[i], to_find))
		i++;

	return (&tab[i]);
}