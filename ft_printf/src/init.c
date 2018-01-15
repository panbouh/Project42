#include "ft_printf.h"

t_flag_list	init_fl()
{
	t_flag_list	new;

	new.sharp = 0;
	new.zero = 0;
	new.min = 0;
	new.plus = 0;
	new.width = 0;
	new.prec = 0;
	new.c_space = ' ';
	return (new);
}