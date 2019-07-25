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

static void	del_data(void **s)
{
	ft_strdel((char **)s);
}

void		del_cli(t_cli *cli)
{
	ft_lstdel(&cli->env_var, &del_data);
	ft_strdel(&cli->pwd);
}

void		init_cli(t_cli *cli)
{
	extern char	**environ;

	ft_bzero(cli, sizeof(t_cli));
	cli->env_var = ft_lsttabsplit(environ);
	cli->pwd = get_pwd();
}
