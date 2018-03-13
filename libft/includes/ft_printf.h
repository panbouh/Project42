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

# define ALL_FLAG	"#0-+ .\0"
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

typedef	struct	s_index
{
	size_t		i;
	int			ret_end;
	int			count;
	int			ret;
}				t_index;

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

int			conv_mod_l(va_list ap, t_flag_list t_fl,
						const char *form, size_t *x);
int			conv_mod_ll(va_list ap, t_flag_list t_fl,
						const char *form, size_t *x);
int			conv_mod_h(va_list ap, t_flag_list t_fl,
						const char *form, size_t *x);
int			conv_mod_hh(va_list ap, t_flag_list t_fl,
						const char *form, size_t *x);

/*
** conv_mod_jz
*/

int			conv_mod_j(va_list ap, t_flag_list t_fl,
						const char *form, size_t *x);
int			conv_mod_z(va_list ap, t_flag_list t_fl,
						const char *form, size_t *x);

/*
** conv_uisc_z_ui.c
*/

int			conv_u(va_list ap, t_flag_list t_fl);
int			conv_id(va_list ap, t_flag_list t_fl);
int			conv_s(va_list ap, t_flag_list t_fl);
int			conv_c(va_list ap, t_flag_list t_fl);
int			conv_zu(va_list ap, t_flag_list t_fl);

/*
** conv_xop_z_id.c
*/

int			conv_o(va_list ap, t_flag_list t_fl);
int			conv_x(va_list ap, t_flag_list t_fl);
int			conv_xm(va_list ap, t_flag_list t_fl);
int			conv_p(va_list ap, t_flag_list t_fl);
int			conv_zid(va_list ap, t_flag_list t_fl);

/*
** conv_l_scox.c 
*/

int			conv_ls(va_list ap, t_flag_list t_fl);
int			conv_lc(va_list ap, t_flag_list t_fl);
int			conv_lo(va_list ap, t_flag_list t_fl);
int			conv_lx(va_list ap, t_flag_list t_fl);
int			conv_lxm(va_list ap, t_flag_list t_fl);

/*
** conv_l_ui_hox.c
*/

int			conv_lu(va_list ap, t_flag_list t_fl);
int			conv_lid(va_list ap, t_flag_list t_fl);
int			conv_ho(va_list ap, t_flag_list t_fl);
int			conv_hx(va_list ap, t_flag_list t_fl);
int			conv_hxm(va_list ap, t_flag_list t_fl);

/*
** conv_h_ui_ll_ox.c
*/

int			conv_hu(va_list ap, t_flag_list t_fl);
int			conv_hid(va_list ap, t_flag_list t_fl);
int			conv_llo(va_list ap, t_flag_list t_fl);
int			conv_llx(va_list ap, t_flag_list t_fl);
int			conv_llxm(va_list ap, t_flag_list t_fl);

/*
** conv_ll_ui_hh_ox.c
*/

int			conv_llu(va_list ap, t_flag_list t_fl);
int			conv_llid(va_list ap, t_flag_list t_fl);
int			conv_hho(va_list ap, t_flag_list t_fl);
int			conv_hhx(va_list ap, t_flag_list t_fl);
int			conv_hhxm(va_list ap, t_flag_list t_fl);

/*
** conv_hh_ui_j_ox.c
*/

int			conv_hhu(va_list ap, t_flag_list t_fl);
int			conv_hhid(va_list ap, t_flag_list t_fl);
int			conv_jo(va_list ap, t_flag_list t_fl);
int			conv_jx(va_list ap, t_flag_list t_fl);
int			conv_jxm(va_list ap, t_flag_list t_fl);

/*
** conv_j_ui_z_ox.c
*/

int			conv_ju(va_list ap, t_flag_list t_fl);
int			conv_jid(va_list ap, t_flag_list t_fl);
int			conv_zo(va_list ap, t_flag_list t_fl);
int			conv_zx(va_list ap, t_flag_list t_fl);
int			conv_zxm(va_list ap, t_flag_list t_fl);

/*
** conv_bonus_b.c
*/

int			conv_b(va_list ap, t_flag_list t_fl);

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

t_index		init_id();
t_flag_list	init_fl();

/*
** utils.c
*/

int			ntmnorm(const char *form, va_list ap, size_t *i, t_flag_list *t_fl);
int			is_conv(char c);
int			nb_bit_print(const wchar_t *wstr, size_t n);
char		*get_mod(const char *str, size_t i);

#endif
