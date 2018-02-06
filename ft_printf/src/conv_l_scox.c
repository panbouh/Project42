/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:58:15 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/16 14:58:15 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include "ft_wuni.h"
/*
**  ls lc lo lx lX
*/

int	conv_wchat(va_list ap, t_flag_list t_fl)
{
	wchar_t	*wstr;
	size_t	size;

	wstr = va_arg(ap, wchar_t *);
	if (!wstr)
	{
		t_fl.neg = 1;
		wstr = ft_wstrdup("(null)");
	}
	size = ft_wstrlen(wstr);
	calc_wp_str(&t_fl, size);
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//print prec of str sinon (null)
	if (wstr && t_fl.put_val)
		ft_putnofwstr(wstr, t_fl.prec);
	else if(!wstr)
		ft_putstr("(null)");
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.neg)
		ft_wstrdel(&wstr);
	return (t_fl.field);
}

int	conv_wintt(va_list ap, t_flag_list t_fl)
{
	wint_t	c;
	c = va_arg(ap, wint_t);
	//calcul width et field
	if ((t_fl.width -= 1) < 0)
		t_fl.width = 0;
	t_fl.field = t_fl.width + 1;
	if (t_fl.zero)
		t_fl.c_width = '0';
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//affichage valeur
	ft_putwchar(c);
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_ulintocta(va_list ap, t_flag_list t_fl)
{
	unsigned long	nb;
	char			*conv;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned long);
	conv = ft_convlu_nbase(nb, 8);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	//calcul : width, prec, field | Define : c_sign, c_width
	if (!((t_fl.sharp && nb) || (t_fl.sharp && !t_fl.put_val)))
		t_fl.sharp = 0;
	calc_wp_num_base(&t_fl, size, t_fl.sharp);
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


int	conv_ulinthexa(va_list ap, t_flag_list t_fl)
{
	unsigned long	nb;
	char			*conv;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned long);
	conv = ft_convlu_nbase(nb, 16);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!nb)
		t_fl.sharp = 0;
	//gestion flag #
	if (t_fl.sharp && (nb || t_fl.put_val))
		ft_putstr("0x");
	//calcul : width, prec, field | Define : c_sign, c_width
	calc_wp_num_base(&t_fl, size, (t_fl.sharp * 2));
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
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


int	conv_ulinthexaup(va_list ap, t_flag_list t_fl)
{
	unsigned long	nb;
	char			*conv;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned long);
	conv = ft_convlu_nbase(nb, 16);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!nb)
		t_fl.sharp = 0;
	//gestion flag #
	if (t_fl.sharp && (nb || t_fl.put_val))
		ft_putstr("0X");
	//calcul : width, prec, field | Define : c_sign, c_width
	calc_wp_num_base(&t_fl, size, (t_fl.sharp * 2));
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
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