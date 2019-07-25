/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:49:35 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/31 16:49:37 by ccatoire         ###   ########.fr       */
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
