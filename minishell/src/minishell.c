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
#include "get_next_line.h"

t_bul_l		g_bultab[] =
{
	{"env", &bul_env},
	{"pwd", &bul_pwd},
	{"cd", &bul_cd},
	{"echo", &bul_echo},
	{NULL, NULL},
};

static int	find_bul(char **cmd, char **env)
{
	size_t	i;

	i = 0;
	while (g_bultab[i].key)
	{
		if (!ft_strcmp(cmd[0], g_bultab[i].key))
		{
			g_bultab[i].f(cmd, env);
			return (OK);
		}
		i++;
	}
	return (FAIL);
}

static int	check_cmd(char *cmd, char **env)
{
	char	**av;

	av = ft_strsplit(cmd, ' ');


	if (find_bul(av, env) == OK)		//cherche un bultins
		return (OK);
	else if (a_out(av, env) == OK)		//sinon cheche un exe
		return (OK);
	ft_tabsdel(av);
	return (FAIL);			//sinon ca existe pas
}

int			minishell(char **env)
{
	char *cmd = NULL;

	while (42)
	{
		ft_strdel(&cmd);							//del anciene commande
		ft_printf("%s>", get_venv("PWD", env));					//prompt degueu
		get_next_line(0, &cmd);						//get cmd
		if (check_cmd(cmd, env) == FAIL)
			ft_printf("minishell: %s : %s\n", cmd, get_onrre(g_onrre));
	}
	ft_strdel(&cmd);
	return (OK);
}
