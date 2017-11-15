/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:28:21 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:21:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

int				get_div(int nb);
void			ft_show_tab(struct s_stock_par *par);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);

typedef struct	s_stock_par
{
	int			size_param;
	char		*str;
	char		*copy;
	char		**tab;
}				t_stock_par;

#endif
