#include "ft_wuni.h"
#include "libft.h"

int	ft_wstrdel(wchar_t	**was)
{
	if (was && *was)
	{
		free(*was);
		*was = NULL;
		return (OK);
	}
	return (FAIL);
}

