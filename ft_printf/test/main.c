#include "ft_printf.h"
#include "limits.h"

void		test_d();


void	print_allconv()
{
		ft_printf("%ls\n%lc\n");
		// ft_printf("%llx\n%llX\n");
		// ft_printf("%ho\n%hx\n%hX\n");
		// ft_printf("%hhi\n%hhu\n%hho\n%hhx\n%hhX\n");
		// ft_printf("%ji\n%ju\n%jo\n%jx\n%jX\n");
		// ft_printf("%zo\n%zx\n%zX\n");
}


//&((*i)++)
#include <locale.h>
int	main(int ac, char **av)
{
	// print_allconv();
	printf("\n------------------------\n");
	//-------------------------------//
//%hhi\n%hhu\n%hho\n%hhx\n%hhX\n
setlocale(LC_ALL, "");
	const char	*bouh = "%10ls";
	int		retr;
	int		retm;
	long long	a = LLONG_MAX;

	ft_putstr("Real : <");
	retr =    printf(bouh, NULL);
	printf(">\n");
	//-------------------------------//
	ft_putstr("Mine : <");
	retm = ft_printf(bouh, NULL);
	printf(">\n");
	//-------------------------------//
	printf("Real ret = %i\n", retr);
	// printf("Mine ret = %i\n", retm);

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