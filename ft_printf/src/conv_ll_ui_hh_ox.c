/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_conv_chiante.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:22 by ccatoire          #+#    #+#             */
/*   Updated: 2018/01/15 16:04:23 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** llu lli
*/

int	conv_llu(va_list ap, t_flag_list t_fl)
{
	unsigned long long	nb;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned long long);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_count_udigit(nb);
	//calcul : width, prec, field | Define : c_sign, c_width
	calc_wp_num(&t_fl, size, 0);
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//affichage de la precision
	ft_putnchar('0', t_fl.prec);
	//affichage de la valuer
	if (t_fl.put_val || nb)
		ft_putunbr(nb);
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_llid(va_list ap, t_flag_list t_fl)
{
	long long		nb;
	size_t			size;

	nb = va_arg(ap, long long);
	//Si nb = 0 ou quon affiche pas la val-> size = 0 (pour le return)
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_count_udigit(ft_abs_ll(nb));
	//Verifier la negativiter
	if (nb < 0)
		t_fl.neg = 1;
	//calcul : width, prec, field | Define : c_sign, c_width
	calc_wp_num(&t_fl, size, 1);
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min && !t_fl.zero)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//affichage du signage
	if (t_fl.plus || t_fl.space || t_fl.neg)
		ft_putchar(t_fl.c_sign);
	//affiche largeur de champ en 0 apres signage si flag 0
	if (!t_fl.min && t_fl.zero)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//affichage de la precision
	ft_putnchar('0', t_fl.prec);
	//affichage de la valuer
	if (t_fl.put_val || nb)
		ft_putunbr(ft_abs_l(nb));
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

/*
** hho hhx hhX
*/

int	conv_hho(va_list ap, t_flag_list t_fl)
{
	unsigned char	nb;
	char			*conv;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned int);
	conv = ft_conv_nbase(nb, 8);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	//calcul : width, prec, field | Define : c_sign, c_width
	if (!((t_fl.sharp && nb) || (t_fl.sharp && !t_fl.put_val)))
		t_fl.sharp = 0;
	calc_wp_num_base(&t_fl, size + t_fl.sharp, 0);
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//affichage de la precision
	ft_putnchar('0', t_fl.prec);
		//gestion flag #
	if ((t_fl.sharp && nb) || (t_fl.sharp && !t_fl.put_val))
		ft_putchar('0');
	//affichage de la valuer
	if (t_fl.put_val || nb)
		ft_putstr(conv);
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_hhx(va_list ap, t_flag_list t_fl)
{
	unsigned char	nb;
	char			*conv;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned int);
	conv = ft_convu_nbase(nb, 16);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!nb)
		t_fl.sharp = 0;
	//calcul : width, prec, field | Define : c_sign, c_width
	calc_wp_num_base(&t_fl, size, (t_fl.sharp * 2));
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//gestion flag #
	if (t_fl.sharp && (nb || t_fl.put_val))
		ft_putstr("0x");
	//affichage de la precision
	ft_putnchar('0', t_fl.prec);
	//affichage de la valuer
	if (t_fl.put_val || nb)
		ft_putstr(conv);
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_hhxm(va_list ap, t_flag_list t_fl)
{
	unsigned char	nb;
	char			*conv;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned int);
	conv = ft_convu_nbase(nb, 16);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!nb)
		t_fl.sharp = 0;
	//calcul : width, prec, field | Define : c_sign, c_width
	calc_wp_num_base(&t_fl, size, (t_fl.sharp * 2));
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//gestion flag #
	if (t_fl.sharp && (nb || t_fl.put_val))
		ft_putstr("0X");
	//affichage de la precision
	ft_putnchar('0', t_fl.prec);
	//affichage de la valuer
	if (t_fl.put_val || nb)
		ft_putstr(ft_strupper(conv));
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}