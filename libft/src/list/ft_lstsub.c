/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:03:51 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:03:53 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstsub(t_list *lst, size_t start, size_t len)
{
	t_list	*new;
	t_node	*tmp;
	t_node	*new_node;

	if (!lst)
		return (NULL);
	new = ft_lstnew();
	tmp = ft_lstgetn(lst, start);
	while (len > 0)
	{
		new_node = ft_lstnew_node(tmp->data, tmp->data_size);
		ft_lstadd_end(new, new_node);
		tmp = tmp->next;
		len--;
	}
	return (new);
}
