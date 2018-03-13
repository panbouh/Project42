#include "libft.h"

void	ft_puttab(const int *tab, size_t size)
{
	size_t	i;

	i = 0;
	ft_putstr("{");
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i < (size - 1))
			ft_putstr(", ");
		i++;
	}
	ft_putstr("}");
}