#include <ft_printf.h>

int		conv_b(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
	char			*conv;
	size_t			size;

	//Si nb = 0 ou quon affiche pas la val -> size = 0 (pour le return)
	nb = va_arg(ap, unsigned int);
	conv = ft_convu_nbase(nb, 2);
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
		ft_putstr("0b");
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
