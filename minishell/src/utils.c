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

#include "minishell.h"

char	*get_pwd()
{
	char	*buff;
	size_t	i;

	buff = ft_strnew(BUFF_MAX);
	i = 0;
	while (!getcwd(buff, BUFF_MAX + i))
	{
		i += sizeof(char) * 42;
		ft_realloc(buff, i);
	}
	return (buff);
}

t_node	*get_venv(char *v_name, t_list *env)
{
	size_t	size;

	if (!v_name || !env)
		return (NULL);
	size = ft_strlen(v_name);
	env->node = env->first;
	while (env->node)
	{
		if (!ft_strncmp(v_name, env->node->data, size))
			return (env->node);
		env->node = env->node->next;
	}
	return (NULL);
}

char	*get_venv_val(char *v_name, t_list *env)
{
	t_node	*venv;
	char	*venv_v;

	if (!(venv = get_venv(v_name, env)))
		return (NULL);
	venv_v = venv->data;
	if (!(venv_v = ft_strchr(venv_v, '=') + 1))
		return (NULL);
	return (venv_v);
}
