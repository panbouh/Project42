#include "ft_ls.h"
#include "ft_printf.h"

void	print_env(t_env env)
{
	ft_printf("option :\nR = %i, a = %i, l = %i, r = %i, t = %i\n",
	 env.rup, env.a, env.l, env.r, env.t);
}

void	print_path(t_env env)
{
	ft_printf("Path :\n");
	ft_putstab((const char**)env.path);
}

void	print_dir(t_env env)
{
	size_t	i;

	i = 0;
	ft_printf("dir_d :\n");
	while (env.dir_d[i])
	{
		ft_printf("name : %s, ino : %i, type : %hhu\n",
			env.dir_d[i]->d_name, env.dir_d[i]->d_ino, env.dir_d[i]->d_type);
		i++;
	}
}

// void	print_st(t_env env)
// 	i = 0;
// 	ft_printf("file_s :\n");
// 	while (&env.file_s[i])
// 	{
// 		ft_printf("ino : %i, taille : %hhu\n",
// 			env.file_s[i].st_ino, env.file_s[i].st_size);
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	t_env	env;

	errno = 0;
	ft_bzero(&env, sizeof(env));
	// print_env(env);
	if (ft_ls(av) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	// ft_ls(av);
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

*/