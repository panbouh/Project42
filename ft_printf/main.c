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

int	main()
{
	const char	*bouh = "<%14-.7i>\n";
	ft_putstr("Real : ");
	   printf(bouh, -4242);
	ft_putstr("Mine : ");
	ft_printf(bouh, -4242);
	return (0);
}


/*
s OK
S
p
d OK ~
D
i OK ~
o
O
u
U
x
X
c
C
*/