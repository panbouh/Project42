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

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*supr;
	t_list	*save;

	if (!alst || !(*alst))
		return ;
	supr = *alst;
	while (supr)
	{
		save = supr->next;
		del(supr->content, supr->content_size);
		free(supr);
		supr = save;
	}
	*alst = NULL;
}
