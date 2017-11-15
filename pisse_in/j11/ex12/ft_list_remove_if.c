/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:03:40 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 18:12:21 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*tmp;
	t_list	*save;

	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	save = *begin_list;
	while (current)
	{
		tmp = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			free(current);
			if (!tmp)
				return ;
			current = tmp;
			save->next = current;
			save = current;
		}
		else
		{
			save = current;	
			current = current->next;
		}
	}
}
