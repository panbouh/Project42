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
#include "get_next_line.h"

t_bul_l		bultab[] =
{
	{"env", &bul_env},
	{"setenv", &bul_setenv},
	{"pwd", &bul_pwd},
	{"cd", &bul_cd},
	{NULL, NULL},
};

static int	find_bul(char *cmd, t_list *env)
{
	size_t	i;
	size_t	cmd_s;
	char	**cmd_t;

	i = 0;
	cmd_s = ft_strlen_till(cmd, ' ');
	ft_putendl(cmd);
	while (bultab[i].key)
	{
		if (!ft_strncmp(cmd, bultab[i].key, cmd_s))
		{
			cmd_t = ft_strsplit(&cmd[cmd_s + 1], ' ');
			bultab[i].f(cmd_t, env);
			ft_tabsdel(cmd_t);
			return (OK);
		}
		i++;
	}
	return (FAIL);
}

static int	check_cmd(char *cmd, t_list *env)
{
	char	**cmd_t;

	if (find_bul(cmd, env) == OK)
		return (OK);
	cmd_t = ft_strsplit(cmd, ' ');
	if (a_out(cmd_t, env) == OK)
	{
		ft_tabsdel(cmd_t);
		return (OK);
	}
	ft_tabsdel(cmd_t);
	return (FAIL);
}

int			minishell(t_cli *cli)
{
	char *cmd = NULL;

	while (42)			//Tant que l'user ne dis pas exit
	{
		ft_strdel(&cmd);							//del anciene commande
		cli->pwd = get_pwd();						//maj du pwd
		ft_printf("%s > ", cli->pwd);					//prompt
		get_next_line(0, &cmd);						//get cmd
		PUTHR
		if (ft_strcmp("exit", cmd) == 0)
			break ;
		if (check_cmd(cmd, cli->env_var) == FAIL)
			ft_printf("minishell: command not found: %s\n", cmd);
		PUTHR
		ft_printf("end :\n");
		// ft_lstputstr(cli->env_var);
	}
	ft_strdel(&cmd);
	return (OK);
}
