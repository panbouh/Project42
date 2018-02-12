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

void	test_mine(const char *bouh);
void	test_real(const char *bouh);
void	test_all(const char *bouh);

void	ft_testmain(int check, const char *bouh)
{
	if (check == 1)
		test_mine(bouh);
	else if (check == 2)
		test_real(bouh);
	else
		test_all(bouh);
}


//&((*i)++)
#include <locale.h>
int	main(int ac, char **av)
{
	// print_allconv();
	// printf("\n------------------------\n");
	//-------------------------------//
//%hhi\n%hhu\n%hho\n%hhx\n%hhX\n
setlocale(LC_ALL, "");

	int fd = open("test", O_RDWR);
	
	int a = 0;
	const char	*bouh = "% l";
	// const char	*bouh = "%#-08x";

	if (av[1])
		a = atoi(av[1]);
	ft_testmain(a, bouh);
	return (0);
}

// "我是一只猫。";


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