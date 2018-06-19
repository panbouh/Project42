/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:02:28 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:02:31 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_printf.h"

t_node	*ft_lstgetn(t_list *lst, size_t n)
{
	size_t	i;
	t_node	*node;

	i = 0;
	if (!lst || !lst->node)
		return (NULL);
	if (n > lst->size)
		return (lst->last);
	node = lst->node;
	while (node && i < n)
	{
		node = node->next;
		i++;
	}
	return (node);
}

t_node	*ft_nodegetn(t_node *node, size_t n)
{
	while (node && n > 0)
	{
		node = node->next;
		n--;
	}
	return (node);
}
