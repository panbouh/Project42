#include "stdlib.h"

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