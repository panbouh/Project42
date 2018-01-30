#include "ft_printf.h"
#include "limits.h"

void		test_d();


//&((*i)++)

int	main(int ac, char **av)
{
	printf("\n------------------------\n");
	//-------------------------------//

	const char	*bouh = "%llu";
	int		retr;
	int		retm;
	long long		a = ULLONG_MAX;

	ft_putstr("Real : <");
	retr =    printf(bouh, a);
	printf(">\n");
	//-------------------------------//
	ft_putstr("Mine : <");
	retm = ft_printf(bouh, a);
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
*/