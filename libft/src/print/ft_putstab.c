/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:07:37 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/27 19:07:38 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstab(const char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
}
