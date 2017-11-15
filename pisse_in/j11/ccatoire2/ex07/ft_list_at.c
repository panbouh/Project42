/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:59:52 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/29 18:00:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int		size(t_list *begin_list)
{
	t_list			*current;
	int				i;

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

t_list				*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!begin_list || nbr > size(begin_list))
		return (NULL);
	while (i < nbr)
	{
		if (!(begin_list = begin_list->next))
			return (NULL);
		i++;
	}
	return (begin_list);
}
