/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:54:45 by ccatoire          #+#    #+#             */
/*   Updated: 2018/08/30 13:54:47 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> 

#include "minishell.h"

static int	stop_error(char *error, char *val)
{
	ft_printf("cd : %s : %s\n", error, val);
	return (1);
}

int			bul_cd(char **av, char **env)
{
	char		*home;
	char		*home_val;
	struct stat	info;

	home = get_venv("HOME", env);
	home_val = get_venv_val("HOME", env);
	if (!av[1])
	{
		if (!home || !home_val)
			return (OK);
		chdir(home_val);
	}
	if (chdir(av[1]) == FAIL)
	{
		if (stat(av[1], &info) == FAIL)
			return (stop_error(E_NOFILE_STR, home_val));
		if (!S_ISDIR(info.st_mode))
			return (stop_error(E_NOTADIR_STR, home_val));
		if (!(S_IRUSR & info.st_mode))
			return (stop_error(E_NOPERM_STR, home_val));
	}
	return (OK);
}
