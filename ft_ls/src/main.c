#include "ft_ls.h"
#include "ft_printf.h"

void	print_env(t_env env)
{
	ft_printf("option :\nR = %i, a = %i, l = %i, r = %i, t = %i\n",
	 env.rup, env.a, env.l, env.r, env.t);
}

void	print_path(t_env env)
{
	ft_printf("----Path :-----\n");
	ft_putstab((const char**)env.path);
	ft_printf("----------------\n");
}


void	lstput(t_list *lst, const char *name)
{
	if (!lst)
	{
		ft_putendl("NULL");
		return ;
	}
	t_node	*node = lst->node;
	ft_printf("%s :\n", name);
	while (node)
	{
		ft_printf("%s->", ((t_finfo*)node->data)->name);
		node = node->next;
	}
	ft_putendl("NULL");
}

/*

	-@ et + devant file
	-leaks tri
	-leaks
	-afficher le bon m_time en fonctoin du tri
	-tri bonnus corriger
	./ft_ls -lRatr  GOLLIET gsdfg dfgdfg sdfg sdfgdf gwe ger wert ewrt wgdfsg sdfgsdf gsdfg dfgsdf gsdfg sdfg dsfg sdfgfd g
*/

int	main(int ac, char **av)
{
	t_env	env;

	errno = 0;
	ft_bzero(&env, sizeof(env));
	// print_env(env);
	// if (ft_ls(av) == FAIL)
	// 	return (ft_error(strerror(errno), FAIL));
	ft_ls(av);
	return (0);
}

/*

option :
	a	: print all
	r	: reverse sort order
	R	: recursive mode
	t	: sort by tome
	l	: long format

	-	=	Regular file.
	d	=	Directory.
	l	=	Symbolic link.
	b	=	Block special file.
	s	=	Socket link.
	c	=	Character special file.
	p	=	FIFO.

right		link	owner	group	bytes	date/hours		pathname
-rw-r--r--	1		bouh	staff	783		9	mar	14:34	Makefile

includes

	-Heure + de 6mois
	{
		1 jours = 24h * 60m * 60s = 86400 sec
		x30 = 2592000 x 3 = 7776000
		x31 = 2678400 x 3 = 8035200
		-> 15811200
	}
*/