/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:57:58 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:19:16 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

typedef struct		s_stock_par
{
	int				size_param;
	char			*str;
	char			*copy;
	char			**tab;
}					t_stock_par;

struct s_stock_par	*ft_param_to_tab(int ac, char **av);
char				**ft_split_whitespaces(char *str);
char				*ft_strdup(char *src);
int					paramlen(char *str);
void				ft_show_tab(struct s_stock_par *par);
void				ft_putchar(char c);

void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_print_words_tables(char **tab);

#endif
