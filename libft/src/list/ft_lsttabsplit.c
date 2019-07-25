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

t_list		*ft_lsttabsplit(char **tab)
{
	t_list	*new;
	size_t	i;

	i = 0;
	new = ft_lstnew();
	while (tab[i])
	{
		ft_lstadd_end(new, ft_lstnew_node(tab[i], ft_strlen(tab[i])));
		i++;
	}
	return (new);
}
