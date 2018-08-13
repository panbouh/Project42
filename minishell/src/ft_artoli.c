/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_artoli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:09:09 by ccatoire          #+#    #+#             */
/*   Updated: 2018/08/13 15:09:11 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

t_list	*ft_artoli(char **src)
{
	size_t	i;
	size_t	size;
	t_list	*new;

	new = ft_lstnew();
	i = 0;
	while(src[i])
	{
		size = ft_strlen(src[i]);
		ft_lstadd_end(new, ft_lstnew_node(src[i], sizeof(char) * size + 1));
		i++;
	}
	return (new);
}
