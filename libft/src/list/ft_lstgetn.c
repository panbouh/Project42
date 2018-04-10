#include "ft_list.h"

t_node	*ft_lstgetn(t_list *lst, size_t n)
{
	size_t	i;
	t_node	*node;

	i = 0;
	if (!lst || !lst->node)
		return (NULL);
	node = lst->node;
	while (node && i < n)
	{
		node = node->next;
		i++;
	}
	return (node);
}