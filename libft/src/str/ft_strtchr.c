#include "libft.h"

#include "ft_printf.h" //dawdwa

char	*ft_strtchr(const char *str, char **to_find)
{
	size_t		i;
	char		*found;

	i = 0;
	while (to_find[i])
	{
		if ((found = ft_strstr(str, to_find[i])))
			return (found);
		// ft_printf("str = %s, to_find = %s\n", str, to_find[i]);
		i++;
	}
	return (NULL);
}