/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 02:02:52 by ccatoire          #+#    #+#             */
/*   Updated: 2019/07/27 02:02:54 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

char	**ft_lsttotab(t_list *lst)
{
	char	**new;
	size_t	i;

	i = 0;
	if (!(new = malloc(sizeof(char*) * lst->size + 1)))
		return (NULL);
	while (lst->node)
	{
		new[i] = ft_strdup(lst->node->data);
		lst->node = lst->node->next;
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**ft_lsttotab_m(t_list *lst)
{
	char	**new;
	size_t	i;

	i = 0;
	if (!(new = malloc(sizeof(char*) * lst->size + 1)))
		return (NULL);
	while (lst->node)
	{
		new[i] = lst->node->data;
		lst->node = lst->node->next;
		i++;
	}
	new[i] = 0;
	return (new);
}
