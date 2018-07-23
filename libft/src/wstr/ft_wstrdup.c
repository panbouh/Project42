/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:35:30 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:35:30 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wuni.h"

wchar_t				*ft_wstrdup(const wchar_t *ws)
{
	wchar_t	*wdup;
	size_t	i;

	i = 0;
	if (!(wdup = malloc(sizeof(wchar_t) * ft_wstrlen(ws) + 1)))
		return (NULL);
	while (ws[i])
	{
		wdup[i] = ws[i];
		i++;
	}
	wdup[i] = 0;
	return (wdup);
}
