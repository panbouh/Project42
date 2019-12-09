/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 23:13:06 by ccatoire          #+#    #+#             */
/*   Updated: 2019/07/27 23:13:07 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onrre.h"
#include <stdlib.h>

t_onrre		g_errtab[] =
{
	{E_NOPERM, E_NOPERM_STR},
	{E_NOFOUND, E_NOFOUND_STR},
	{E_NOTADIR, E_NOTADIR_STR},
	{E_NOFILE, E_NOFILE_STR},
	{-4896, 0},
};

char	*get_onrre(int onrre)
{
	size_t	i;

	i = 0;
	while(g_errtab[i].err_tag)
	{
		if (onrre == g_errtab[i].err_tag)
			return (g_errtab[i].err_str);
		i++;
	}
	return (E_IDK_STR);
}
