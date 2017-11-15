/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:24:12 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 16:53:09 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*current;
	t_list	*new;

	if (!(new = ft_create_elem(data)))
		return ;
	if (!(begin_list))
		return ;
	if (!(*begin_list))
	{
		*begin_list = new;
		return ;
	}
	current = *begin_list;
	new->next = current;
	*begin_list = new;
}
