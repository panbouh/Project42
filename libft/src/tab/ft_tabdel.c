#include "libft.h"
#include "ft_printf.h"

void	ft_tabdel(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_memdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}