#include "ft_printf.h"

void	flag_int(va_list ap)
{
	int	nb;

	nb = va_arg(ap, int);
	ft_putnbr(nb);
}

void	flag_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c + 48);
}

void	flag_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr(str);
}

// void	flags_int(va_list ap)
// {

// }

// void	flags_int(va_list ap)
// {

// }