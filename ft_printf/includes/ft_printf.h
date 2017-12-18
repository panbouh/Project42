/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:03:49 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/16 15:03:49 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"


# define SKIP_SPACE		*i = ft_skip_char(form, *i, ' ', ALL);

typedef	struct	s_flag_list
{
	char		c_space;
	char		sharp;
	char		zero;
	char		min;
	char		plus;
	int			width;
	int			prec;
}				t_flag_list;

typedef	struct	s_conv
{
	char		*key;
	void	(*f)(va_list, t_flag_list);
}				t_conv;

typedef	struct	s_flag
{
	char		key;
	void		(*f)(t_flag_list*);
}				t_flag;

//conv_bas.c
void		conv_int(va_list ap, t_flag_list t_fl);
void		conv_char(va_list ap, t_flag_list t_fl);
void		conv_str(va_list ap, t_flag_list t_fl);

//err.c (printf.c)
int			conv_nothing(t_flag_list t_fl, char c);
int			ret_err();

//flag.c
void		flag_sharp(t_flag_list *f_list);
void		flag_zero(t_flag_list *f_list);
void		flag_min(t_flag_list *f_list);
void		flag_plus(t_flag_list *f_list);

//ft_printf.c
int			ft_printf(const char *format, ...);
void		ion_ft(const char *form, size_t *i, t_flag_list *t_fl);
int			do_conv(const char *form, size_t *i, t_flag_list t_fl, va_list ap);
int			found_flags(const char *form, va_list ap, size_t *i);

//calc.c
void		calc_wp_num(t_flag_list *t_fl, int size);
void		calc_wp_str(t_flag_list *t_fl, int size);


//init.c (main.c)
t_flag_list	init_fl();

#endif
