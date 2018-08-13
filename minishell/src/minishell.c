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
	{NULL, NULL},
};

static int	find_bul(char *cmd)
{
	size_t	i;

	i = 0;
	while (bultab[i].key)
	{
		if (!ft_strcmp(cmd, bultab[i].key))
		{
			bultab[i].f();
			return (OK);
		}
		i++;
	}
	return (FAIL);
}

static int	check_cmd(char *cmd)
{
	if (find_bul(cmd) == OK)
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
		if (check_cmd(cmd) == FAIL)
			ft_printf("minishell: command not found: %s\n", cmd);
	}
	ft_strdel(&cmd);
	return (OK);
}
