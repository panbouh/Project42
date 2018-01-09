#include "ft_printf.h"

void	conv_int(va_list ap, t_flag_list t_fl)
{
	int		nb;

	nb = va_arg(ap, int);
	// printf("\n1) w = %i\np = %i\n", t_fl.width, t_fl.prec);
	calc_wp_num(&t_fl, ft_count_digit(ft_abs(nb)));
	// printf("\n2) w = %i\np = %i\n", t_fl.width, t_fl.prec);

	if (nb < 0 && !t_fl.plus)
		t_fl.width--;
	if (!t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);
	if (t_fl.plus && nb >= 0)
		ft_putchar('+');
	if (nb < 0)
		ft_putchar('-');
	ft_putnchar('0', t_fl.prec);
	ft_putnbr(ft_abs(nb));
	if (t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);
}

void	conv_unsigned(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	calc_wp_num(&t_fl, ft_count_digit(ft_abs(nb)));	
	if (t_fl.plus)
		t_fl.width++;
	if (!t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);
	ft_putnchar('0', t_fl.prec);
	ft_putunbr(ft_abs(nb));
	if (t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);
}

void	conv_str(va_list ap, t_flag_list t_fl)
{
	char	*str;

	str = va_arg(ap, char *);
	// printf("\nwitdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	calc_wp_str(&t_fl, ft_strlen(str));

	// printf("min = %i\n", t_fl.min);
	// printf("witdh = %i\n", t_fl.width);
	// printf("prec  = %i\n", t_fl.prec);

	if (!t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);

	ft_putnofstr(str, t_fl.prec);


	if (t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);

}



void	conv_char(va_list ap, t_flag_list t_fl)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	(void)t_fl;
	ft_putchar(c);
}


// void	flags_(va_list ap, t_flag_list t_fl)
// {

// }

// void	flags_(va_list ap, t_flag_list t_fl)
// {

// }