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

#include "ft_printf.h"
#include "ft_list.h"

t_list	*ft_lstcat(t_list *dest, t_list *src)
{
	t_list	*tmp;

	tmp = dest;
	if (!src || !dest || !src->node)
		return (dest);
	ft_lstadd_end(dest, src->node);
	return (tmp);
}
