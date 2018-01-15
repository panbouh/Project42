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
	char		key;
	void		(*f)(va_list, t_flag_list);
}				t_conv;

typedef	struct	s_mod
{
	char		*key;
	void		(*f)(va_list, t_flag_list, char);
}				t_mod;

typedef	struct	s_flag
{
	char		key;
	void		(*f)(t_flag_list*);
}				t_flag;

/*
** conv_mod_lhllhh
*/
void	conv_mod_l(va_list ap, t_flag_list t_fl, char form);
void	conv_mod_ll(va_list ap, t_flag_list t_fl, char form);
void	conv_mod_h(va_list ap, t_flag_list t_fl, char form);
void	conv_mod_hh(va_list ap, t_flag_list t_fl, char form);

/*
** conv_mod_jz
*/
void	conv_mod_j(va_list ap, t_flag_list t_fl, char form);
void	conv_mod_z(va_list ap, t_flag_list t_fl, char form);

/*
** conv_iusc.c
*/
void		conv_int(va_list ap, t_flag_list t_fl);
void		conv_char(va_list ap, t_flag_list t_fl);
void		conv_str(va_list ap, t_flag_list t_fl);
void		conv_unsigned(va_list ap, t_flag_list t_fl);

/*
** conv_xob.c
*/

void		conv_hexa(va_list ap, t_flag_list t_fl);
void		conv_hexaup(va_list ap, t_flag_list t_fl);
void		conv_octa(va_list ap, t_flag_list t_fl);
void		conv_bina(va_list ap, t_flag_list t_fl);

/*
** conv_l_scox.c 
*/
void	conv_wchat(va_list, t_flag_list t_fl);
void	conv_wintt(va_list, t_flag_list t_fl);
void	conv_ulintocta(va_list, t_flag_list t_fl);
void	conv_ulinthexa(va_list, t_flag_list t_fl);
void	conv_ulinthexaup(va_list, t_flag_list t_fl);

/*
** conv_l_ui_hox.c
*/
void	conv_ulongint(va_list, t_flag_list t_fl);
void	conv_long(va_list ap, t_flag_list t_fl);
void	conv_ushortocta(va_list, t_flag_list t_fl);
void	conv_ushorthexa(va_list, t_flag_list t_fl);
void	conv_ushorthexaup(va_list, t_flag_list t_fl);

/*
** conv_h_ui_ll_ox.c
*/
void	conv_ushort(va_list, t_flag_list t_fl);
void	conv_short(va_list, t_flag_list t_fl);
void	conv_ullintocta(va_list, t_flag_list t_fl);
void	conv_ullinthexa(va_list, t_flag_list t_fl);
void	conv_ullinthexaup(va_list, t_flag_list t_fl);

/*
** conv_ll_ui_hh_ox.c
*/

void	conv_ullongint(va_list, t_flag_list t_fl);
void	conv_llong(va_list, t_flag_list t_fl);
void	conv_ucharocta(va_list, t_flag_list t_fl);
void	conv_ucharhexa(va_list, t_flag_list t_fl);
void	conv_ucharhexaup(va_list, t_flag_list t_fl);

/*
** conv_hh_ui.c
*/
void	conv_schar(va_list, t_flag_list t_fl);
void	conv_uchar(va_list, t_flag_list t_fl);

/*
** -----------------------------------------------------------------------------
*/

/*
** err.c
*/
int			conv_nothing(t_flag_list t_fl, char c);
int			ret_err();

/*
** flag.c
*/
void		flag_sharp(t_flag_list *f_list);
void		flag_zero(t_flag_list *f_list);
void		flag_min(t_flag_list *f_list);
void		flag_plus(t_flag_list *f_list);

/*
** ft_printf.c
*/
int			ft_printf(const char *format, ...);
void		ion_ft(const char *form, size_t *i, t_flag_list *t_fl);
int			do_conv(const char *form, size_t *i, t_flag_list t_fl, va_list ap);
int			found_flags(const char *form, va_list ap, size_t *i);

/*
** calc.c
*/
void		calc_wp_num(t_flag_list *t_fl, int size);
void		calc_wp_str(t_flag_list *t_fl, int size);


/*
** init.c
*/
t_flag_list	init_fl();

#endif
