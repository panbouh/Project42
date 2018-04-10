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

void	ft_lstdelone(t_list *lst, t_node **anode)
{
	t_node *tmp;

	if (!anode || !(*anode))
		return ;
	tmp = *anode;
	if (tmp->back)
		tmp->back->next = tmp->next;
	else
	{
		tmp->back = NULL;
		lst->first = tmp->next;
	}
	if (tmp->next)
		tmp->next->back = tmp->back;
	else
	{
		tmp->next = NULL;
		lst->last = tmp->back;
	}
	ft_memdel(&(*anode)->data);
	ft_memdel((void **)anode);
	if (!lst->node)
		*anode = lst->first;
}
