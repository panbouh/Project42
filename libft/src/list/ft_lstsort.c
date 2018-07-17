/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:23:15 by ccatoire          #+#    #+#             */
/*   Updated: 2018/07/17 15:23:17 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include "libft.h"
#include "ft_printf.h"

static t_node	*sort(t_node *nd, int (*cmp)(t_node *, t_node*))
{
	t_node	*first;

	first = nd;
	while (nd && nd->next)
	{
		if (cmp(nd, nd->next))
		{
			ft_lstswap(nd, nd->next);
			nd = first;
		}
		else
			nd = nd->next;
	}
	return (first);
}

t_list			*ft_lstsort(t_list *lst, int (*cmp)(t_node *, t_node *))
{
	lst->first = sort(lst->first, cmp);
	lst->node = lst->first;
	lst->last = ft_lstgetn(lst, lst->size);
	return (lst);
}
