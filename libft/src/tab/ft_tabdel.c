#include "libft.h"
#include "ft_printf.h"

void	ft_tabsdel(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}