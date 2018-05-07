#include "libft.h"
#include "stdlib.h"

void	**ft_tabdup(void **src, size_t size)
{
	void	**new;
	void	**tmp;
	size_t	i;

	i = 0;
	if (!(new = malloc(sizeof(size))))
		return (NULL);
	tmp = new;
	while (i < size)
	{
		tmp = ft_memdup(src, sizeof(src));
		tmp++;
		src++;
		i++;
	}
	tmp = 0;
	return (new);
}

char	**ft_tabsdup(char **src)
{
	char	**new;
	size_t	i;
	size_t	size;

	size = ft_tablen(src) + 1;
	i = 0;
	if (!(new = malloc(sizeof(char *) * size)))
		return (NULL);
	while (src[i])
	{
		new[i] = ft_strdup(src[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}