#include <sys/types.h>

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