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

int	bul_echo(char **av, char **env)
{
	size_t	i;

	i = 1;
	(void)env;
	while (av[i])
	{
		ft_putstr(av[i]);
		i++;
		if (av[i])
			PUTSPACE
	}
	PUTBR
	return (OK);
}
