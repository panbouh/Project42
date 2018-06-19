#include "ft_list.h"

size_t	ft_lstlen(t_node *n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n = n->next;
		i++;
	}
	return (i);
}