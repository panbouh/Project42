#include "ft_list.h"

static t_list	*merge(t_list *lst_l, t_list *lst_r,
						int (*cmp)(t_node *, t_node *))
{
	t_list	*result;
	int		ret;

	if (!lst_l || !lst_r)
		return (NULL);
	result = ft_lstnew(); //malloc
	while (lst_l->node && lst_r->node)
	{
		if ((ret = cmp(lst_l->node, lst_r->node)) == -1)
			return (NULL);
		if (ret)
		{
			ft_lstadd_end(result, lst_r->node);
			lst_r->node = lst_r->node->next;
		}
		else
		{
			ft_lstadd_end(result, lst_l->node);
			lst_l->node = lst_l->node->next;
		}
	}
	result = ft_lstcat(result, lst_l);
	result = ft_lstcat(result, lst_r);
	return (result);
}

t_list	*ft_lstsort(t_list *lst, int (*cmp)(t_node *, t_node *))
{
	t_list	*lst_r;
	t_list	*lst_l;
	t_list	*result;
	size_t	size;

	if ((size = lst->size) <= 1)
		return (lst);
	lst_l = ft_lstsub(lst, 0, size / 2); //malloc
	lst_r = ft_lstsub(lst, size / 2, (size - size / 2)); //malloc
	ft_lstdel(&lst);	//leaks evidents
	lst_l = ft_lstsort(lst_l, cmp);
	lst_r = ft_lstsort(lst_r, cmp);
	if (!(result = merge(lst_l, lst_r, cmp)))	//malloc
		return (NULL);
	return (result);
}