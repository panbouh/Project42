/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:49:35 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/31 16:49:37 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_end(t_list *lst, t_node *node)
{
	if (lst->node)
	{
		node->back = lst->last;
		lst->last->next = node;
		lst->last = node;
	}
	else
		ft_lstinit(lst, node);
	lst->size++;
}

void	ft_lstadd_begin(t_list *lst, t_node *node)
{
	if (lst->node)
	{
		node->next = lst->first;
		lst->first->back = node;
		lst->first = node;
	}
	else
		ft_lstinit(lst, node);
	lst->node = lst->first;
	lst->size++;
}
