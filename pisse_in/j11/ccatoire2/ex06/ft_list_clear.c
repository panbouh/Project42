/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:30:20 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 16:00:54 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_clear(t_list **begin_list)
{
	t_list	*current;
	t_list	*tmp;
	int		i;

	i = 0;
	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	tmp = *begin_list;
	while (current)
	{
		tmp = current->next;
		if (current)
			free(current);
		current = tmp;
	}
	*begin_list = NULL;
}
