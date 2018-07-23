/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:03:31 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:03:33 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

static void		del_l_r(t_list	**lst_r, t_list	**lst_l)
{
	ft_memdel((void**)lst_r);
	ft_memdel((void**)lst_l);
}

static t_list	*merge(t_list *lst_l, t_list *lst_r,
						int (*cmp)(t_node *, t_node *))
{
	t_list	*result;
	int		ret;

	if (!lst_l || !lst_r)
		return (NULL);
	result = ft_lstnew();
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
	del_l_r(&lst_r, &lst_l);
	return (result);
}

t_list			*ft_lstsort(t_list *lst, int (*cmp)(t_node *, t_node *), 
															void(*del)(void**))
{
	t_list	*lst_r;
	t_list	*lst_l;
	t_list	*result;
	size_t	size;

	if ((size = lst->size) <= 1)
		return (lst);
	lst_l = ft_lstsub(lst, 0, size / 2);
	lst_r = ft_lstsub(lst, size / 2, (size - size / 2));
	ft_lstdel(&lst, del);
	lst_l = ft_lstsort(lst_l, cmp, del);
	lst_r = ft_lstsort(lst_r, cmp, del);
	if (!(result = merge(lst_l, lst_r, cmp)))
		return (NULL);
	return (result);
}
