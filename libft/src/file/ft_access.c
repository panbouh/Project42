/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 23:07:23 by ccatoire          #+#    #+#             */
/*   Updated: 2019/07/27 23:07:24 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "onrre.h"
#include <sys/stat.h>

int		ft_access(char *file)
{
	struct stat	info;

	if (stat(file, &info) == FAIL)
		return (set_onrre(E_NOFILE, FAIL));
	if (!(S_IRUSR & info.st_mode))
		return (set_onrre(E_NOPERM, FAIL));
	return (OK);
}
