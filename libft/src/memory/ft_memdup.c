/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:14:14 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:14:16 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t size)
{
	void	*new;
	void	*tmp;

	tmp = new + size;
	new = ft_memalloc(size);
	new = ft_memcpy(new, src, size);
	tmp = NULL;
	return (new);
}
