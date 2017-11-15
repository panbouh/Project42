/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 07:47:51 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 13:33:17 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int	list_size(t_list *begin_list)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

t_list			*list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!begin_list || nbr > list_size(begin_list))
		return (NULL);
	while (i < nbr)
	{
		if (!(begin_list = begin_list->next))
			return (NULL);
		i++;
	}
	return (begin_list);
}

void			ft_list_reverse(t_list **begin_list)
{
	t_list			*last;
	t_list			*first;
	t_list			save;
	unsigned int	i;
	unsigned int	size;

	if (!begin_list || !*begin_list)
		return ;
	i = 0;
	size = list_size(*begin_list) - 1;
	first = *begin_list;
	last = list_at(*begin_list, size);
	while (i < (size / 2))
	{
		save = *first;
		*first = *last;
		first->next = save.next;
		*last = save;
		last->next = NULL;
		last = list_at(*begin_list, ((size - i) - 1));
		i++;
	}
}
