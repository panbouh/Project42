#include "libft.h"

char *ft_addbit(char *bin)
{
	char	*new;
	size_t	size;
	int		rest;
	int		byte;

	byte = 8;
	size = ft_strlen(bin);
	while ((int)size > byte)
		byte += byte;
	rest = size % byte;
	if (!rest)
		return (ft_strdup(bin));
	rest = byte - rest;
	new = ft_strnew(size + rest);
	ft_memset(new, '0', rest);
	ft_strcat(new, bin);
	return (new);
}