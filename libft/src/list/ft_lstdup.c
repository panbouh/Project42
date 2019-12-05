/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:10:24 by ccatoire          #+#    #+#             */
/*   Updated: 2019/07/29 13:10:29 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new;

	new = ft_lstnew();
	lst->node = lst->first;
	while (lst->node)
	{
		ft_lstadd_end(new, ft_lstnew_node(lst->node->data,
														lst->node->data_size));
		lst->node = lst->node->next;
	}
	return (new);
}
