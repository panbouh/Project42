#include "ft_list.h"
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

void		ad_print(t_node *n, char *name)
{
	ft_printf("%s :\n", name);
	if (!n)
	{
		ft_putstr("NULL\n");
		return ;
	}
	ft_printf("%p->", n->back);
	while (n)
	{
		ft_printf("%p<=>", n);
		n = n->next;
	}
	ft_printf("%p\n", n);
}

t_node	*add_end(t_node *dest, t_node *src, char all)
{
	t_node	*tmp;

	// ad_print(src, "src");
	if (!src)
		return (dest);
	if (!dest)
	{
		dest = src;
		if (dest->next)
			dest->next = NULL;
		return (dest);
	}
	tmp = dest;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = src;
	tmp->next->back = tmp;

	if (!all)
		if (tmp->next->next)
			tmp->next->next = NULL;
	return (dest);
}

static t_node	*merge(t_node *lst_l, t_node *lst_r,
												int (*cmp)(t_node *, t_node *))
{
	t_node	*result;
	int		ret;

	result = NULL;
	if (!lst_l || !lst_r)
		return (NULL); // WTF?
BR
	ft_printf("on merge :\n");
	ad_print(lst_r, "lst_r");
	ad_print(lst_l, "lst_l");
	while (lst_l && lst_r)
	{
		if ((ret = cmp(lst_l, lst_r)) == -1)
			return (NULL);	//a voir??
		if (ret)
		{
			result = add_end(result, lst_r, NO);
			ad_print(result, "result ret");
			lst_r = lst_r->next;
		}
		else
		{
			result = add_end(result, lst_l, NO);
			ad_print(result, "result !ret");
			lst_l = lst_l->next;
			
		}
	}
	result = add_end(result, lst_r, YES);
	ad_print(result, "result end r");
	result = add_end(result, lst_l, YES);
	ad_print(result, "result end l");
	return (result);
}

t_node	*cutme(t_node *all)
{
	t_node	*all_r;
	size_t	size;

	size = (ft_lstlen(all) / 2);

	all_r = ft_nodegetn(all, size);
	if (all_r && all_r->back)	//invcalid read
		all_r->back->next = NULL;
	if (all_r)
		all_r->back = NULL;
	return (all_r);
}

t_node	*sort(t_node *all, int (*cmp)(t_node *, t_node *))
{
	t_node	*lst_r;
	t_node	*lst_l;
	t_node	*result;
	size_t	size;

	if ((size = ft_lstlen(all)) <= 1){
		return (all); //size??
	}
	lst_l = all;
	lst_r = cutme(all);
	

	lst_l = sort(lst_l, cmp);
	lst_r = sort(lst_r, cmp);

	result = merge(lst_l, lst_r, cmp);
	// ft_printf("merge = %p\n", result);
	return (result);
}

void	test_sort(t_list *lst, int (*cmp)(t_node *, t_node *))
{
	ad_print(lst->first, "unsort");
	HR
	lst->first = sort(lst->first, cmp);
	HR
	ad_print(lst->first, "sort");
	lst->node = lst->first;
	lst->last = ft_lstgetn(lst, lst->size);
}