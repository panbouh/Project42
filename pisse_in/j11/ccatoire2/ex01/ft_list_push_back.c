/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:17:56 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 09:03:07 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*current;

	if(!(new = ft_create_elem(data)))
		return ;
	if (!(begin_list))
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new;
		return ;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = new;
}
