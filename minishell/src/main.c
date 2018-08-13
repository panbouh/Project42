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

int	main(void)
{
	t_cli	*env;

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