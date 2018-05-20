/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:04:03 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:04:07 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstswap(t_node *lst1, t_node *lst2)
{
	void	*tmp;
	size_t	s_save;

	s_save = lst1->data_size;
	tmp = lst1->data;
	lst1->data = lst2->data;
	lst1->data_size = lst2->data_size;
	lst2->data = tmp;
	lst2->data_size = s_save;
}
