
#include "ft_printf.h"

void	flag_sharp(t_flag_list *t_fl)
{
	t_fl->sharp = 1;
}

void	flag_zero(t_flag_list *t_fl)
{
	t_fl->zero = 1;
}

void	flag_min(t_flag_list *t_fl)
{
	t_fl->min = 1;
}

void	flag_plus(t_flag_list *t_fl)
{
	t_fl->plus = 1;
}

void	flag_space(t_flag_list *t_fl)
{
	t_fl->space = 1;
}