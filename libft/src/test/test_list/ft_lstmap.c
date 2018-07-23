/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:00:25 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/31 17:00:26 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*new;
	t_list	*begin;

	result = f(lst);
	if (!(begin = ft_lstnew(result->content, result->content_size)))
		return (NULL);
	new = begin;
	lst = lst->next;
	while (lst)
	{
		result = f(lst);
		if (!(new->next = ft_lstnew(result->content, result->content_size)))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
