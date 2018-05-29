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
#include "ft_printf.h"

void	ft_lstdelone(t_list *lst, t_node **anode, void(*del)(void**))
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
	ft_printf("je      del %p, ", (*anode)->data);
	ft_printf("et %p\n", *anode);
	del((*anode)->data);
	free(*anode);
	anode = NULL;
}