/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:19:27 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/24 16:42:48 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# define ERROR	-1
# define OK		0

typedef	struct		s_opp
{
	char			*key;
	void			(*f)(int, int);
}					t_opp;

int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_add(int a, int b);
void				ft_sub(int a, int b);
void				ft_div(int a, int b);
void				ft_mod(int a, int b);
void				ft_mul(int a, int b);
void				ft_usage(int a, int b);

#endif
