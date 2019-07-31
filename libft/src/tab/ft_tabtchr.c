#include "libft.h"

char	**ft_tabtchr(char **tab, char **to_find)
{
	size_t	i;

	i = 0;

	while (tab[i] && !ft_strtchr(tab[i], to_find))
		i++;
	if (&tab[i])
		return (&tab[i]);
	else
		return (NULL);
}