/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:18:32 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/31 16:18:33 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

t_node		*ft_lstnew_node(const void *data, size_t data_size)
{
	t_node	*new;

	if (!(new = ft_memalloc(sizeof(t_node))))
		return (NULL);
	if (data)
	{
		if (!(new->data = ft_memalloc(data_size)))
			return (NULL);
		new->data = ft_memcpy(new->data, data, data_size);
		new->data_size = data_size;
	}
	return (new);
}

/*
**	Sans copier la data
*/

t_node		*ft_lstnew_node_m(void *data, size_t data_size)
{
	t_node	*new;

	if (!(new = ft_memalloc(sizeof(t_node))))
		return (NULL);
	if (data)
	{
		new->data = data;
		new->data_size = data_size;
	}
	return (new);
}

t_list		*ft_lstnew(void)
{
	t_list	*new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return (NULL);
	return (new);
}
