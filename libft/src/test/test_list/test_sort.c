#include "libft.h"
#include "ft_list.h"

#include "ft_printf.h"

static void		insert_nd(t_list *dest, t_node *src, int (*cmp)(t_node*, t_node*))
{
	t_node	*nd_d;
	size_t	i;

	i = 0;
	nd_d = dest->first;
	while (nd_d && nd_d == src && cmp(nd_d, src))
	{
		i++;
		nd_d = nd_d->next;
	}
	ft_lstmove(dest, src, i);
}

static t_node	*sort(t_list *lst, int (*cmp)(t_node*, t_node*))
{
	t_node	*first;
	t_node	*nd;

	nd = lst->first;
	first = nd;

	while (nd && nd->next)
	{
		if (!cmp(nd, nd->next))
		{
			insert_nd(lst, nd, cmp);
			nd = first;
		}
		nd = nd->next;
	}
	return (NULL);
}

t_list	*test_sort(t_list *lst, int (*cmp)(t_node*, t_node*))
{
	lst->first = sort(lst, cmp);
	lst->node = lst->first;
	lst->last = ft_lstgetn(lst, lst->size);
	return (lst);
}