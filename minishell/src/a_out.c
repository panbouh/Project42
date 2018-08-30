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


#include <errno.h>
#include <string.h>
/*
**	a.out looooool
*/

char	*find_exe(char *name, char *path)
{
	char	buff[BUFF_MAX];
	size_t	i;
	size_t	stop = 0;

	i = 0;
	if (!access(name, F_OK))
		return (ft_strdup(name));
	i = ft_skip_char(path, i, '=', TILL) + 1;
	while (path[i])
	{
		stop = ft_strlen_till(&path[i], ':');
		// ft_printf("path :\n%s\n", &path[i]);
		ft_bzero(buff, BUFF_MAX);

		ft_strncat(buff, &path[i], stop);
		ft_strcat(buff, "/");
		ft_strcat(buff, name);

		// ft_printf("buff :\n%s\n", buff);
		if (!access(buff, F_OK))
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

	pid = fork();
	if (pid == 0)
	{
		if (execve(exe, &av[0], env) == FAIL)
		{
			// ft_printf("execve : %s\n", strerror(errno)); //ndawndkwand
			ft_strdel(&exe);
			return (FAIL);
		}
	}
	else
		wait(0);
	ft_strdel(&exe);
	return (OK);
}
