/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:11:15 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 15:59:16 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_back_2(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*current;

	if (!(new = ft_create_elem(data)))
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

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list	*new;
	int		i;

	i = 1;
	if (ac == 0 || av == NULL)
		return (NULL);
	if (!(new = ft_create_elem(av[0])))
		return (NULL);
	while (i < ac)
	{
		ft_list_push_back_2(&new, av[i]);
		i++;
	}
	return (new);
}
