/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:06:06 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/26 23:15:52 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE02_H
# define COLLE02_H

# include <stdlib.h>

typedef	struct	s_info_glue
{
	int			id;
	int			x;
	int			y;
}				t_info_glue;

/*
** main.c
*/
t_info_glue		check_colle(char **colle);

/*
** print.c
*/
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putcolle(t_info_glue glue);

/*
** get_out.c
*/
char			*get_out();
char			*ft_realloc(char *str, int new_size);

/*
** get_tab.c
*/
char			*get_line(char *str, int *x);
char			**ft_putlineintab(char *str);
int				ft_strlen(char *str, char stop);
int				ft_get_nbline(char *str);

#endif
