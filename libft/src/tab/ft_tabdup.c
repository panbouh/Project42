#include "libft.h"
#include "stdlib.h"

#include "ft_printf.h"
void	**ft_tabdup(void **src, size_t size)
{
	void	**new;
	void	**tmp;
	size_t	i;

	i = 0;
	new = malloc(sizeof(size));
	tmp = new;
	while (i < size)
	{
		tmp = src;
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

	i = 0;
	new = malloc(sizeof(char *) * ft_tablen(src));
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = 0;
	return (new);
}