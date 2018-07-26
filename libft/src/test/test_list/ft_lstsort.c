/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:45:15 by ccatoire          #+#    #+#             */
/*   Updated: 2018/07/20 15:45:17 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void		ins_nd(t_list *dest, t_node *src, int (*cmp)(t_node*, t_node*))
{
	t_node	*nd_d;
	size_t	i;

	i = 0;
	nd_d = dest->first;
	while (nd_d && (nd_d == src || cmp(src, nd_d)))
	{
		i++;
		nd_d = nd_d->next;
	}
	ft_lstmove(dest, src, i);
}

void			ft_lstsort_ins(t_list *lst, int (*cmp)(t_node*, t_node*))
{
	t_node	*nd;

	nd = lst->first;
	while (nd && nd->next)
	{
		if (cmp(nd, nd->next))
		{
			ins_nd(lst, nd, cmp);
			nd = lst->first;
		}
		else
			nd = nd->next;
	}
}
