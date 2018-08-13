/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:08:31 by ccatoire          #+#    #+#             */
/*   Updated: 2018/08/08 15:08:32 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

char	*get_pwd()
{
	char	*buff;
	size_t	i;

	buff = ft_strnew(BUFF_MAX);
	i = 0;
	while (!getcwd(buff, BUFF_MAX + i))
	{
		i += sizeof(char) * 42;
		ft_realloc(buff, i);
	}
	return (buff);
}

int		bul_pwd()
{
	char	*pwd;

	pwd = get_pwd();
	ft_putendl(pwd);
	ft_strdel(&pwd);
	return (OK);
}