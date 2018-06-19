/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:26:37 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/31 16:26:41 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

void	ft_lstdelone(t_list *lst, t_node **anode, void (*del)(void**))
{
	if (lst->size > 1)
	{
		if ((*anode)->next)
			(*anode)->next->back = (*anode)->back;
		if ((*anode)->back)
			(*anode)->back->next = (*anode)->next;
		if (lst->first == *anode)
		{
			lst->first = (*anode)->next;
			lst->node = lst->first;
		}
		if (lst->last == *anode)
			lst->last = (*anode)->back;
	}
	del(&(*anode)->data);
	free(*anode);
	*anode = NULL;
	lst->size--;
}
