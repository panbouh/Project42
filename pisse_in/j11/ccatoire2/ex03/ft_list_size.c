/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:04:32 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/29 17:51:23 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_list_size(t_list *begin_list)
{
	t_list	*current;
	int		i;

	if (!(begin_list))
		return (0);
	i = 0;
	current = begin_list;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
