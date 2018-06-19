#include "libft.h"
#include "ft_list.h"

static t_node	*ft_return_new(int new_size, t_node *new)
{
	while (new_size-- >= 1 && new)
		new = new->next;
	return (new);
}

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

t_node			*merge(t_node *old, int old_size, t_node *new, int new_size,
						int (*cmp)(t_node *, t_node *))
{
	int			i;
	int			size;

	size = (ft_lstlen(old) - 1);
	i = -1;
	while (i++ < size && old)
	{
		if (new->next && old->next && cmp(old, new))
		{
			ft_lstswap(new, old);
			if (new_size == 1)
				break ;
			new_size--;
		}
		else
		{
			if (old_size == 1 && new)
				return (ft_return_new(new_size, new));
			old_size--;
		}
		old = old->next;
	}
	return (new);
}

t_node			*sort(t_node *old, size_t size, int (*cmp)(t_node *, t_node *))
{
	int			new_size;	//qsize
	int			old_size;	//psize
	t_node		*new;		//q, qsize

	new_size = (size / 2);
	old_size = (size - new_size);

	if (old_size >= 2)
	{
		old = sort(old, old_size, cmp);
		if (new_size >= 2)
			sort(new, new_size, cmp);
	}
	else
		new = old->next;
	new = merge(old, old_size, new, new_size, cmp);
	return (new);
}

t_list			*test_sort(t_list *lst, int (*cmp)(t_node *, t_node *))
{
	lst->first = sort(lst->first, lst->size, cmp);
	lst->node = lst->first;
	lst->last = ft_lstgetn(lst, lst->size);
	return (lst);
}
