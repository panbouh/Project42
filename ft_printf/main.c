#include "ft_printf.h"
#include "limits.h"

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

int	main(int ac, char **av)
{
	const char	*bouh = "<%#15.8x>\n";

	int	a = 30098;
	ft_putstr("Real : ");
	   printf(bouh, a);
	// ft_putstr("Rea2 : ");
	//    printf("<%x>\n", a);
	ft_putstr("Mine : ");
	ft_printf(bouh, a);
	// ft_putstr(ft_conv_n_base(bouh, 16));

	// printf("<%#x>\n", &a);
	// printf("<%08X>\n", a);
	// printf("<%i>\n", &a);
	// printf("<%p>\n", a);
	return (0);
}


/*
s OK
S
p
d OK
D
i OK
o OK
O
u OK
U
x OK
X OK
c OK
C
*/