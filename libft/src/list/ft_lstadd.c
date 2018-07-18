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
void	ft_lstadd_end(t_list *dest, t_node *src)
{
	if (dest->first)
	{
		src->back = dest->last;
		dest->last->next = src;
		dest->last = src;
	}
	else
		ft_lstinit(dest, src);
	dest->size = ft_lstlen(dest->first);
}

void	ft_lstadd_begin(t_list *dest, t_node *src)
{
	if (dest->first)
	{
		src->next = dest->first;
		dest->first->back = src;
		dest->first = src;
	}
	else
		ft_lstinit(dest, src);
	dest->node = dest->first;
	dest->size = ft_lstlen(dest->first);
}

void	ft_lstadd_at(t_list *dest, t_node *src, size_t n)
{
	t_node	*curr;
	t_node	*prev;

	if (n == 0)
		ft_lstadd_begin(dest, src);
	else if (n >= dest->size)
		ft_lstadd_end(dest, src);
	else if (n < dest->size)
	{
		curr = ft_lstgetn(dest, n);
		prev = curr->back;
		prev->next = src;
		curr->back = src;
		src->next = curr;
		src->back = prev;
	}
	dest->size = ft_lstlen(dest->first);
}
