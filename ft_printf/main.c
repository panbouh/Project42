#include "ft_printf.h"
#include "limits.h"



int	main(int ac, char **av)
{
	const char	*bouh = "<%40i>\n";
	int		ret;
	int		a = 12346;

	ft_putstr("Real : ");
	ret =    printf(bouh, a);
	printf("Real ret = %i\n", ret);
	ft_putstr("Mine : ");
	ret = ft_printf(bouh, a);
	printf("Mine ret = %i\n", ret);
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