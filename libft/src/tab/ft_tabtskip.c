#include "libft.h"

char	**ft_tabtskip(char **tab, char **to_find)
{
	size_t	i;

	i = 0;

	while (tab[i])
	{
		if (!ft_strtchr(tab[i], to_find))
			return (&tab[i]);
		i++;
	}
	return (NULL);
}