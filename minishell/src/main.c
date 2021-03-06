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
	g_onrre = 0;
	t_cli	cli;

	init_cli(&cli);

	minishell(&cli);

	del_cli(&cli);
	return (OK);
}

/*
	Bultins :
		-echo
		-cd
		-setenvg
		-unsetenv
		-env
		-exit
	Expension :
		-~
		-$
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