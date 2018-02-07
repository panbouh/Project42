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

int	conv_u(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned int);
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

int	conv_id(va_list ap, t_flag_list t_fl)
{
	int			nb;
	size_t		size;

	nb = va_arg(ap, int);
	//Si nb = 0 ou quon affiche pas la val-> size = 0 (pour le return)
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_count_udigit(ft_abs(nb));
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
		ft_putunbr(ft_abs(nb));
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

// t_fl->width - t_fl->prec - size - t_fl->plus

int	conv_s(va_list ap, t_flag_list t_fl)
{
	char	*str;
	size_t	size;

	str = va_arg(ap, char *);
	if (!str)
	{
		t_fl.neg = 1;
		str = ft_strdup("(null)");
	}
	size = ft_strlen(str);
	calc_wp_str(&t_fl, size);
	//affichage largeur de champ a gauche (sans -)
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	//print prec of str sinon (null)
	if (str && t_fl.put_val)
		ft_putnofstr(str, t_fl.prec);
	else if(!str)
		ft_putstr("(null)");
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.neg)
		ft_strdel(&str);
	return (t_fl.field);
}

int	conv_c(va_list ap, t_flag_list t_fl)
{
	unsigned char	c;
	c = (unsigned char)va_arg(ap, int);
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
	ft_putchar(c);
	//affichage largeur de champ a droite (avec -)
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}

int	conv_zu(va_list ap, t_flag_list t_fl)
{
	size_t	nb;
	size_t	size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, size_t);
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
