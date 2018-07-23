/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:35:05 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:35:06 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_wuni.h"

const t_mask_uni	g_masktab_len[] =
{
	{"0xxxxxxx\0", 7},
	{"110xxxxx10xxxxxx\0", 11},
	{"1110xxxx10xxxxxx10xxxxxx\0", 16},
	{"11110xxx10xxxxxx10xxxxxx10xxxxxx\0", 21},
	{NULL, 0},
};

size_t	ft_wcharlen(const wchar_t c)
{
	char	*conv;
	size_t	size;
	size_t	i;

	conv = ft_conv_nbase(c, 2);
	size = ft_strlen(conv);
	i = 0;
	while (size > g_masktab_len[i].size)
		i++;
	ft_strdel(&conv);
	return (i + 1);
}
