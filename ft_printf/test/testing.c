#include "ft_printf.h"

void	print_tfl(t_flag_list t_fl)
{
	printf("\n------------t_flag_list-----------\n");
	printf("c_width = (%c)\nc_sign = (%c)\nsharp = (%i)\nzero = (%i)\n", t_fl.c_width, t_fl.c_sign, t_fl.sharp, t_fl.zero);
	printf("min = (%i)\nplus = (%i)\nspace = (%i)\n", t_fl.min, t_fl.plus, t_fl.space);
	printf("put_val = (%i)\nneg = (%i)\n", t_fl.put_val, t_fl.neg);
	printf("width = (%i)\nprec = (%i)\nfield = (%i)\n", t_fl.width, t_fl.prec, t_fl.field);
	printf("-------------------------------------\n");
}