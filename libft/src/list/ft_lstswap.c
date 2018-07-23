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

void	ft_lstswap(t_node *nd1, t_node *nd2)
{
	void	*tmp;
	size_t	s_save;

	tmp = nd1->data;
	s_save = nd1->data_size;
	nd1->data = nd2->data;
	nd1->data_size = nd2->data_size;
	nd2->data = tmp;
	nd2->data_size = s_save;
}
