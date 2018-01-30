#include "ft_printf.h"
#include "limits.h"

void		test_d();


void	print_allconv()
{
	ft_printf("%ls\n%lc\n%llx\n%llX\n\n%ho\n%hx\n%hX\n%hhi\n%hhu\n%hho\n%hhx\n%hhX\n%ji\n%ju\n%jo\n%jx\n%jX\n%zi\n%zu\n%zo\n%zx\n%zX\n");
}

//&((*i)++)

int	main(int ac, char **av)
{
	print_allconv();
	printf("\n------------------------\n");
	//-------------------------------//

	const char	*bouh = "%lx";
	int		retr;
	int		retm;
	unsigned long		a = ULONG_MAX;

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