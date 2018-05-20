/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:17:26 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:17:26 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_wuni.h"

void	ft_putwstr(const wchar_t *wstr)
{
	size_t	i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}
