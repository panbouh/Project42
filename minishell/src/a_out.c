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

#include "minishell.h"
#include "unistd.h"

// #include <sys/types.h>
#include <dirent.h>
#include <errno.h>	//delete
#include <string.h>	//delete
/*
**	a.out looooool
*/

int		check_exe(char *exe)
{
	if (!access(exe, F_OK))
	{
		if (!opendir(exe))
			return (OK);
		return (set_onrre(E_NOPERM, FAIL));
	}
	return (set_onrre(E_NOFOUND, FAIL));
}

char	*find_exe(char *name, char *path)
{
	char	buff[BUFF_MAX];
	size_t	i;
	size_t	stop = 0;

	i = 0;
	if (check_exe(name) == OK)
		return (ft_strdup(name));
	
	i = ft_skip_char(path, i, '=', TILL) + 1;

	if (ft_strchr(name, '/'))		//si name est un chemin, check pas dans path
		i = 0;
	
	while (path[i] && i)
	{
		stop = ft_strlen_till(&path[i], ':');
		// ft_printf("path :\n%s\n", &path[i]);
		ft_bzero(buff, BUFF_MAX);

		ft_strncat(buff, &path[i], stop);
		ft_strcat(buff, "/");
		ft_strcat(buff, name);

		// ft_printf("buff :\n%s\n", buff);
		if (check_exe(buff) == OK)
			return (ft_strdup(buff));
		i += stop + 1;
		// PUTHR
	}
	return (NULL);
}

int		a_out(char **av, char **env)
{
	char	*exe;
	pid_t	pid;

	if (!(exe = find_exe(av[0], get_venv("PATH", env))))
			return (FAIL);
	// ft_printf("av0 = %s\n", av[0]);
	pid = fork();
	if (pid == 0)
	{
		if (execve(exe, &av[0], env) == FAIL)
		{
			// ft_printf("execve : %s\n", strerror(errno)); //ndawndkwand
			ft_strdel(&exe);
			return (set_onrre(E_IDK, FAIL));
		}
	}
	else
		wait(0);
	ft_strdel(&exe);
	return (OK);
}
