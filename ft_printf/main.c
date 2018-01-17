#include "ft_printf.h"
#include "limits.h"



int	main(int ac, char **av)
{
	const char	*bouh = "<%1.3i>\n";
	int		retr;
	int		retm;
	int		a = INT_MAX;

	ft_putstr("Real : ");
	retr =    printf(bouh, a);
	//-------------------------------//
	ft_putstr("Mine : ");
	retm = ft_printf(bouh, a);
	//-------------------------------//
	printf("Real ret = %i\n", retr);
	printf("Mine ret = %i\n", retm);
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