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
	t_node	*del_me;

	del_me = *anode;
	if (lst->size > 1)
	{
		if (del_me->back != NULL)
			del_me->back->next = del_me->next;
		if (del_me->next != NULL)
			del_me->next->back = del_me->back;
		if (lst->first == del_me)
		{
			lst->first = del_me->next;
			lst->node = lst->first;
		}
		if (lst->last == del_me)
			lst->last = del_me->back;
	}
	del(&del_me->data);
	free(del_me);
	del_me = NULL;
	lst->size--;
}
