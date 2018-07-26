/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:45:22 by ccatoire          #+#    #+#             */
/*   Updated: 2018/07/20 15:45:23 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstmove(t_list *dest, t_node *src, size_t n)
{
	t_node	*prev;
	t_node	*front;

	if (ft_lstgetn(dest, n) == src)
		return ;
	prev = src->back;
	front = src->next;
	if (prev)
		prev->next = front;
	if (front)
		front->back = prev;
	src->next = NULL;
	src->back = NULL;
	dest->size--;
	if (src == dest->first)
		dest->first = front;
	if (src == dest->last)
		dest->last = prev;
	ft_lstadd_at(dest, src, n);
}
