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

#include "onrre.h"
#include "minishell.h"

static int	stop_error(char *error, char *val)
{
	ft_printf("cd: %s: %s\n", error, val);
	return (1);
}

char	*opt_finder(char **av, char *opt)	//place la derniere option valide dans op et renvoi av au bon endroit
{
	size_t	y;
	size_t	x;

	y = 0;
	*opt = 'x';
	while (av[y] && av[y][0] == '-')
	{
		x = 1;
		while (av[y][x])
		{
			if (av[y][x] != 'L' && av[y][x] != 'P')
				return (NULL);
			x++;
		}
		*opt = av[y][x - 1];
		y++;
	}
	if (y > 0)
		return (av[y]);
	return (av[0]);
}

int		is_pathok(char *path)
{
	int			file;
	struct stat	info;

	if (lstat(path, &info) == FAIL)
		return (set_onrre(E_NOFILE, FAIL));
	if ((file = whats_my_file(path)) != W_DIR && file != W_LNK)
		return (set_onrre(E_NOTADIR, FAIL));
	if (!(S_IRUSR & info.st_mode))
		return (set_onrre(E_NOPERM, FAIL));
	return (OK);
}

char	*path_finder(char *ope, char *cdpath)
{
	(void)cdpath;

	if (is_pathok(ope) == FAIL)
		return (NULL);

	return (ft_newpath(get_pwd(), ope));


	// char	*path;
	// while (cdpath && (file = whats_my_file(ope)) != W_DIR)
	// {

	// }

}

int			bul_cd(char **av, t_list *env)
{
	char		*home;
	char		*cdpath;
	char		*operand;
	char		*new_path;				//pour pas alterer operand en cas d'erreur..........
	char		opt;		


	home = get_venv_val("HOME", env);
	cdpath = get_venv_val("CDPATH", env);

	operand = opt_finder(&av[1], &opt);

	if (!operand)
	{
		if (!home)
			return (OK);
		if (is_pathok(home) == FAIL)
			return (stop_error(get_onrre(g_onrre), home));
		new_path = home;
	}

	else if (!(new_path = path_finder(operand, cdpath)))
		return (stop_error(get_onrre(g_onrre), operand));

	// ft_printf("new_path = <%s>\n", new_path);

	chdir(new_path);

	ft_strdel(&new_path);
	return (OK);
}
