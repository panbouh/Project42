/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:26:37 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/31 16:26:41 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"
#include "ft_printf.h"
void	ft_lstdelone(t_list *lst, t_node **anode)
{
	t_node *tmp;
	t_node *anow;

	if (!anode || !(*anode))
		return ;
	tmp = *anode;
	anow = tmp->next;
	(void)lst;
	ft_printf("je del ---> : %s, qui a %p\n", tmp->data, tmp);
	ft_printf("anow = ---> : %s, qui a %p\n", anow->data);

	if (anow)
	{
		anow->back = tmp->back;
		if (anow->back)
			anow->back->next = anow;
	}

	ft_printf("lstfirst = %s\n", (*anode)->data);
	ft_printf("lstfirst = %s\n", lst->first->data);

	ft_memdel(&tmp->data);
	ft_printf("-data deleted\n");
	ft_memdel((void **)anode);
	ft_printf("-node deleted\n");

	if (!lst->first)
		lst->first = anow;
}
