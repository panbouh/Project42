#include "ft_ls.h"

void	print_data(t_env env)
{
	ft_putstr("l = ");
	ft_putnbr(env.l);
	ft_putchar(',');
	ft_putstr(" r = ");
	ft_putnbr(env.r);
	ft_putchar(',');
	ft_putstr(" rup = ");
	ft_putnbr(env.rup);
	ft_putchar(',');
	ft_putstr(" t = ");
	ft_putnbr(env.t);
	ft_putchar(',');
	ft_putstr(" a = ");
	ft_putnbr(env.a);
	ft_putchar('\n');
	ft_putstab((const char**)env.path);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	// print_env(env);
	if (ft_ls(av) == FAIL)
		return (ft_error("problem", FAIL));
	return (0);
}

/*

option :
	a	: print all
	r	: reverse sort order
	R	: recursive mode
	t	: sort by tome
	l	: long format

	b	=	Block special file.
	c	=	Character special file.
	d	=	Directory.
	l	=	Symbolic link.
	s	=	Socket link.
	p	=	FIFO.
	-	=	Regular file.

right		link	owner	group	bytes	date/hours		pathname
-rw-r--r--	1		bouh	staff	783		9	mar	14:34	Makefile


*/