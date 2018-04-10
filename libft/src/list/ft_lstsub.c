#include "ft_list.h"

// #include "../../../ft_ls/includes/ft_ls.h"
// #include "ft_printf.h"
t_list	*ft_lstsub(t_list *lst, size_t start, size_t len)
{
	t_list	*new;
	t_node	*tmp;
	t_node	*new_node;

	if (!lst)
		return (NULL);
	new = ft_lstnew();
	tmp = ft_lstgetn(lst, start);
	while (len > 0)
	{
		new_node = ft_lstnew_node(tmp->data, tmp->data_size);
		ft_lstadd_end(new, new_node);
		tmp = tmp->next;
		len--;
	}
	return (new);
}