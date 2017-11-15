/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:14:13 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/24 14:45:50 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# define ERROR	-1
# define OK		0
# define OP(x) x

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	do_sum(int a, int b);
void	do_sub(int a, int b);
void	do_div(int a, int b);
void	do_mod(int a, int b);
void	do_mult(int a, int b);

#endif
