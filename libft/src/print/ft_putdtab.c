#include "libft.h"

void	ft_putdtab(const int **tab, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while(i < y)
	{
		ft_puttab(tab[i], x);
		ft_putstr(";\n");
		i++;
	}
}
