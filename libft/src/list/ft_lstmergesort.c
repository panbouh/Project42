#include "ft_list.h"
#include "libft.h"
#include "ft_printf.h"

void	add_end(t_node *dest, t_node *src)
{
	// if (!dest)
	// 	dest = src;
	if (!src)
		return ;
	while (dest)
		dest = dest->next;
	dest = src;
}

static t_node	*merge(t_node *lst_l, t_node *lst_r,
												int (*cmp)(t_node *, t_node *))
{
	t_node	*result;
	int		ret;

	result = NULL;
	if (!lst_l || !lst_r)
		return (NULL);
	while (lst_l && lst_r)
	{
		if ((ret = cmp(lst_l, lst_r)) == -1)
			return (NULL);
		if (ret)
		{
			add_end(result, lst_l);
			lst_l = lst_l->next;
		}
		else
		{
			add_end(result, lst_r);
			lst_r = lst_r->next;
		}
	}
	add_end(result, lst_r);
	add_end(result, lst_l);
	return (result);
}

t_node	*cutme(t_node *all)
{
	t_node	*all_r;
	size_t	size;

	size = (ft_lstlen(all) / 2) + 1;

	all_r = ft_nodegetn(all, size);
	all_r->back->next = NULL;
	all_r->back = NULL;
	return (all_r);
}

t_node	*sort(t_node *all, int (*cmp)(t_node *, t_node *))
{
	t_node	*lst_r;
	t_node	*lst_l;
	t_node	*result;
	size_t	size;

	if ((size = ft_lstlen(all)) <= 1) //size??
		return (all);

	lst_l = all;
	lst_r = cutme(all);

	lst_l = sort(lst_l, cmp);
	lst_r = sort(lst_r, cmp);
	if (!(result = merge(lst_l, lst_r, cmp)))
		return (NULL);
	return (result);
}

t_list			*test_sort(t_list *lst, int (*cmp)(t_node *, t_node *))
{
	lst->first = sort(lst->first, cmp);
	lst->node = lst->first;
	lst->last = ft_lstgetn(lst, lst->size);
	return (lst);
}