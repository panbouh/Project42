/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:02:06 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:02:09 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstcat(t_list *dest, t_list *src)
{
	t_list	*tmp;

	tmp = dest;
	if (!src || !dest || !src->node)
		return (dest);
	src->node = src->first;
	ft_lstadd_end(dest, src->node);
	dest->size += src->size;
	dest->last = src->last;
	return (tmp);
}

t_list	*ft_lstncat(t_list *dest, t_list *src, size_t n)
{
	t_list	*tmp;

	tmp = dest;
	if (!src || !dest || !src->node)
		return (dest);
	src->node = src->first;
	ft_lstadd_end(dest, src->node);
	while (n > 0)
	{
		dest->node = dest->node->next;
		n--;
	}
	dest->last = dest->node;
	dest->node = NULL;
	dest->size += n;
	dest->node = dest->first;
	return (tmp);
}
