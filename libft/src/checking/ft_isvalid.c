#include "libft.h"

int		ft_isvalid(char c, char *valid)
{
	size_t	i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (OK);
		i++;
	}
	return (FAIL);
}