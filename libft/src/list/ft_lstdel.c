/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:37:54 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/31 16:37:56 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void**))
{
	t_node	*tmp;
	t_node	*save;

	if (!alst || !(*alst))
		return ;
	tmp = (*alst)->first;
	while (tmp)
	{
		save = tmp->next;
		del(&(tmp->data));
		ft_memdel(&(tmp->data));
		ft_memdel((void**)&tmp);
		tmp = save;
	}
	ft_memdel((void**)alst);
	alst = NULL;
}
