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
	{"pwd", &bul_pwd},
	{"cd", &bul_cd},
	{NULL, NULL},
};

static int	find_bul(char *cmd, t_list *env)
{
	size_t	i;
	size_t	cmd_s;

	i = 0;
	cmd_s = ft_strlen_till(cmd, ' ');
	ft_putendl(cmd);
	while (bultab[i].key)
	{
		if (!ft_strncmp(cmd, bultab[i].key, cmd_s))
		{
			bultab[i].f(ft_strsplit(cmd, ' '), env);
			return (OK);
		}
		i++;
	}
	return (FAIL);
}

static int	check_cmd(char *cmd, t_list *env)
{
	if (find_bul(cmd, env) == OK)
		return (OK);
	return (FAIL);
}

int			minishell(t_cli *env)
{
	char *cmd = NULL;

	while (42)					//Tant que l'user ne dis pas exit
	{
		ft_strdel(&cmd);							//del anciene commande
		ft_printf("%s>", env->pwd);					//prompt
		get_next_line(0, &cmd);						//get cmd
		if (check_cmd(cmd, env->env_var) == FAIL)
			ft_printf("minishell: command not found: %s\n", cmd);
	}
	ft_strdel(&cmd);
	return (OK);
}
