/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttabsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 02:03:09 by ccatoire          #+#    #+#             */
/*   Updated: 2019/07/27 02:03:10 by ccatoire         ###   ########.fr       */
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

t_list		*ft_lsttabsplit_m(char **tab)
{
	t_list	*new;
	size_t	i;

	i = 0;
	new = ft_lstnew();
	while (tab[i])
	{
		ft_lstadd_end(new, ft_lstnew_node_m(tab[i], ft_strlen(tab[i])));
		i++;
	}
	return (new);
}

/*
**	en cas de tableau static degueulasse (genre ceux du systeme sans \0 toussa)
*/

t_list		*ft_lsttabsplit_t(char **tab)
{
	t_list	*new;
	char	*tmp;
	size_t	size;
	size_t	i;

	i = 0;
	new = ft_lstnew();
	while (tab[i])
	{
		size = ft_strlen(tab[i]);
		if (!(tmp = malloc(sizeof(char) * size + 1)))
			return (NULL);
		ft_strcpy(tmp, tab[i]);
		ft_lstadd_end(new, ft_lstnew_node_m(tmp, size + 1));
		i++;
	}
	return (new);
}
