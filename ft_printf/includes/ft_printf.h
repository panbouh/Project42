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
# include <stdarg.h>
# include <stddef.h>

# define ALL_FLAG	"#0-+ .\0";
# define NB_FLAG	6

typedef	struct	s_flag_list
{
	char		c_width;
	char		c_sign;
	char		sharp;
	char		zero;
	char		min;
	char		plus;
	char		space;
	char		neg;
	char		put_val;
	int			width;
	int			prec;
	int			field;
}				t_flag_list;

typedef	struct	s_conv
{
	char		key;
	int			(*f)(va_list, t_flag_list);
}				t_conv;

typedef	struct	s_mod
{
	char		*key;
	int			(*f)(va_list, t_flag_list, const char *, size_t *);
}				t_mod;

typedef	struct	s_flag
{
	char		key;
	void		(*f)(t_flag_list*);
}				t_flag;

/*
** conv_mod_lhllhh
*/
int			conv_mod_l(va_list ap, t_flag_list t_fl, const char *form, size_t *x);
int			conv_mod_ll(va_list ap, t_flag_list t_fl, const char *form, size_t *x);
int			conv_mod_h(va_list ap, t_flag_list t_fl, const char *form, size_t *x);
int			conv_mod_hh(va_list ap, t_flag_list t_fl, const char *form, size_t *x);

/*
** conv_mod_jz
*/
int			conv_mod_j(va_list ap, t_flag_list t_fl, const char *form, size_t *x);
int			conv_mod_z(va_list ap, t_flag_list t_fl, const char *form, size_t *x);

/*
** conv_uisc_z_ui.c
*/
int			conv_unsigned(va_list ap, t_flag_list t_fl);
int			conv_int(va_list ap, t_flag_list t_fl);
int			conv_str(va_list ap, t_flag_list t_fl);
int			conv_char(va_list ap, t_flag_list t_fl);
int			conv_sizet(va_list ap, t_flag_list t_fl);


/*
** conv_xob.c
*/

int			conv_hexa(va_list ap, t_flag_list t_fl);
int			conv_hexaup(va_list ap, t_flag_list t_fl);
int			conv_octa(va_list ap, t_flag_list t_fl);
int			conv_bina(va_list ap, t_flag_list t_fl);

/*
** conv_l_scox.c 
*/
int			conv_wchat(va_list ap, t_flag_list t_fl);
int			conv_wintt(va_list ap, t_flag_list t_fl);
int			conv_ulintocta(va_list ap, t_flag_list t_fl);
int			conv_ulinthexa(va_list ap, t_flag_list t_fl);
int			conv_ulinthexaup(va_list ap, t_flag_list t_fl);

/*
** conv_l_ui_hox.c
*/
int			conv_ulongint(va_list ap, t_flag_list t_fl);
int			conv_long(va_list ap, t_flag_list t_fl);
int			conv_ushortocta(va_list ap, t_flag_list t_fl);
int			conv_ushorthexa(va_list ap, t_flag_list t_fl);
int			conv_ushorthexaup(va_list ap, t_flag_list t_fl);

/*
** conv_h_ui_ll_ox.c
*/
int			conv_ushort(va_list ap, t_flag_list t_fl);
int			conv_short(va_list ap, t_flag_list t_fl);
int			conv_ullintocta(va_list ap, t_flag_list t_fl);
int			conv_ullinthexa(va_list ap, t_flag_list t_fl);
int			conv_ullinthexaup(va_list ap, t_flag_list t_fl);

/*
** conv_ll_ui_hh_ox.c
*/

int			conv_ullongint(va_list ap, t_flag_list t_fl);
int			conv_llong(va_list ap, t_flag_list t_fl);
int			conv_ucharocta(va_list ap, t_flag_list t_fl);
int			conv_ucharhexa(va_list ap, t_flag_list t_fl);
int			conv_ucharhexaup(va_list ap, t_flag_list t_fl);

/*
** conv_hh_ui_j_ox.c
*/
int			conv_schar(va_list ap, t_flag_list t_fl);
int			conv_uchar(va_list ap, t_flag_list t_fl);
int			conv_uintmaxtocta(va_list ap, t_flag_list t_fl);
int			conv_uintmaxthexa(va_list ap, t_flag_list t_fl);
int			conv_uintmaxthexaup(va_list ap, t_flag_list t_fl);

/*
** conv_j_ui_z_ox.c
*/
int			conv_uintmaxt(va_list ap, t_flag_list t_fl);
int			conv_intmaxt(va_list ap, t_flag_list t_fl);
int			conv_sizethexa(va_list ap, t_flag_list t_fl);
int			conv_sizethexaup(va_list ap, t_flag_list t_fl);
int			conv_sizetocta(va_list ap, t_flag_list t_fl);



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
void		flag_space(t_flag_list *f_list);

/*
** ft_printf.c
*/
void		check_for_pw(const char *form, size_t *y, t_flag_list *t_fl);
int			ft_printf(const char *format, ...);
int			check_for_flag(char c, t_flag_list *t_fl);
int			do_conv(const char *form, va_list ap, size_t *i, t_flag_list *t_fl);
int			found_flag(const char *form, va_list ap, size_t *i);

/*
** calc.c
*/
void		calc_wp_num(t_flag_list *t_fl, long size, int is_sign);
void		calc_wp_str(t_flag_list *t_fl, int size);
void		calc_wp_num_base(t_flag_list *t_fl, long size, int sharp);

/*
** init.c
*/
t_flag_list	init_fl();

/*
** utils.c
*/
int			is_conv(char c);
char		*get_mod(const char *str, size_t i);

//testing
void		print_tfl(t_flag_list t_fl);

#endif
