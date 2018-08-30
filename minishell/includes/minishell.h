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

#ifndef		MINISHELL_H
# define	MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "ft_list.h"

# define	PRINT	1
# define	NOPRINT	2

typedef struct	s_cli
{
	t_list	*env_var;
	char	*pwd;
}				t_cli;

typedef struct	s_bul_l
{
	char	*key;
	int		(*f)();
}				t_bul_l;

/*
**	minishell.c
*/
int		minishell(t_cli *env);

/*
**	init.c
*/
t_cli	*init_env();
void	del_env(t_cli *env);

/*
**	libft
*/
t_list	*ft_artoli(char **src);
void	*ft_realloc(void *src, size_t size);

/*
**	Bultins
*/
char	*get_pwd();
int		bul_pwd();
int		bul_cd(char **av, t_list *env);

#endif
