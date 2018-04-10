#include "ft_list.h"

void	ft_lstinit(t_list *lst, t_node *node)
{
		lst->node = node;
		lst->first = node;
		lst->last = node;
}