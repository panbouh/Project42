/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:45:28 by ccatoire          #+#    #+#             */
/*   Updated: 2018/07/20 15:45:28 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

void	ft_lstput(t_list *lst, void (*put)(t_node nd))
{
	t_node	*nd;

	if (!lst)
		return ;
	nd = lst->first;
	while (nd)
	{
		put(*nd);
		nd = nd->next;
	}
}

void	ft_lstputstr(t_list *lst)
{
	t_node	*nd;

	if (!lst)
		return ;
	nd = lst->first;
	while (nd)
	{
		ft_putendl(nd->data);
		nd = nd->next;
	}
}
