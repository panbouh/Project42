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

#include "ft_printf.h"

void	ft_lstdel(t_list **alst)
{
	t_node	*tmp;

	if (!alst || !(*alst))
		return ;
	tmp = (*alst)->first;
	while (tmp)
	{
		ft_printf("dell : %s, next : %s\n", tmp->data, tmp->next);
		ft_lstdelone(*alst, &tmp);
	}
	ft_memdel((void**)alst);
}
