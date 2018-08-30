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

int	main()
{
	char	**env;

	env = init_env();

	minishell(env);

	del_env(env);
	return (OK);
}

/*
	Bultins :
		-echo
		-cd
		-setenv
		-unsetenv
		-env
		-exit
	fonction autorisee :
		-malloc,free
		-access
		-open, close, read, write
		-opendir, readdir, closedir
		-getcwd, chdir
		-stat, lstat, fstat
		-fork, execve
		-wait, waitpid, wait3, wait4
		-signal, kill
		-exit
*/