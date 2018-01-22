#include "ft_printf.h"
#include "limits.h"

void		test_d();

int	main(int ac, char **av)
{
	test_d();
	printf("\n------------------------\n");
	//-------------------------------//

	const char	*bouh = "%.d, %.0d";
	int		retr;
	int		retm;
	int		a = 0;

	ft_putstr("Real : <");
	retr =    printf(bouh, a, a);
	printf(">\n");
	//-------------------------------//
	ft_putstr("Mine : <");
	retm = ft_printf(bouh, a, a);
	printf(">\n");
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
...............T....
*/