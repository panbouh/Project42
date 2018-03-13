#include "libft.h"
#include "ft_wuni.h"
#include "limits.h"
#include <locale.h>

int	main(int ac, char **av)
{

	int		*tab;
	int		**bouh;
	size_t	size;
	char	*str = "1 2 3\n4 5 3\n7 8 9\0";

	bouh = ft_tabsplit(str);

	ft_putdtab(bouh, 3, 3);
	return (1);
}