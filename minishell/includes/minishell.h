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
# include "onrre.h"

# define	PRINT	1
# define	NOPRINT	2

typedef struct	s_bul_l
{
	char	*key;
	int		(*f)();
}				t_bul_l;

typedef struct	s_cli
{
	t_list	*env_var;
	char	*pwd;
}				t_cli;

/*
**	libft
// */
// void	*ft_realloc(void *src, size_t size);

/*
**	minishell.c
*/
int		minishell(t_cli *env);

/*
**	init.c
*/
void	init_cli(t_cli *cli);
void	del_cli(t_cli *cli);

/*
**	utils.c
*/
char	*get_venv(char *v_name, t_list *env);
char	*get_venv_val(char *v_name, t_list *env);
char	*get_pwd();

/*
**	libft
*/
t_list	*ft_artoli(char **src);
void	*ft_realloc(void *src, size_t size);

/*
**	Bultins.c
*/
int		bul_env(char **av, char **env);
int		bul_pwd();
int		bul_echo(char **av, char **env);
int		bul_cd(char **av, char **env);

/*
**	a_out.c
*/
int		a_out(char **av, t_list *env);

#endif
