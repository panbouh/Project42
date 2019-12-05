/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whats_my_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 02:01:53 by ccatoire          #+#    #+#             */
/*   Updated: 2019/07/27 02:01:54 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "libft.h"

#include "ft_printf.h"

int		whats_my_file(char *file)
{
	struct stat	info;

	lstat(file, &info);
	if (S_ISREG(info.st_mode))
		return (W_REG);
	if (S_ISDIR(info.st_mode))
		return (W_DIR);
	if (S_ISLNK(info.st_mode))
		return (W_LNK);
	if (S_ISCHR(info.st_mode))
		return (W_CHR);
	if (S_ISBLK(info.st_mode))
		return (W_BLK);
	if (S_ISFIFO(info.st_mode))
		return (W_FIF);
	if (S_ISSOCK(info.st_mode))
		return (W_SOK);
	return (W_IDK);
}
