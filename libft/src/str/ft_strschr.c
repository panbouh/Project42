#include "libft.h"

char	*ft_strschr(const char *str, const char *to_find)
{
	size_t		i;
	char		*found;

	i = 0;
	while (to_find[i])
	{
		if ((found = ft_strchr(str, to_find[i])))
			return (found);
		i++;
	}
	return (NULL);
}