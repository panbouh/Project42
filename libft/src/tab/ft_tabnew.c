#include "stdlib.h"

int		**ft_new_tab(int x, int y)
{
	int		**new;
	size_t	i;

	i = 0;
	if (!x || !y)
		return (NULL);
	if ((new = malloc(sizeof(int *) * y)))
		return (NULL);
	while (y < 0)
	{
		new[i++] = malloc(sizeof(int) * x);
		y--;
	}
	return (new);
}