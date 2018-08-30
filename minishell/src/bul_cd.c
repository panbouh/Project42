#include "minishell.h"


// static void test_print(t_node bouh)
// {
// 	ft_putendl(bouh.data);
// }

int	bul_cd(char **av, t_list *env)
{
	ft_putendl("------------cd-----------");
	(void)env;
	if (av){
		ft_putendl("OK");
		ft_putstab(av);
	}
	else
		ft_putendl("none av");
	return (OK);
}