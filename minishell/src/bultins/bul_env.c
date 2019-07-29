#include "minishell.h"
#include "ft_printf.h"

t_list	*new_env(char **av, t_list *old)
{
	size_t	i;
	t_list	*new;

	i = 0;
	if (!old){
		new = ft_lstnew();
	}
	else{
		new = ft_lstdup(old);
	}
	bul_setenv(av, new);

	return (new);
}

int		bul_env(char **av, t_list *env)
{
	if (!av[1])
	{
		ft_lstputstr(env);
		return (OK);
	}
	if (av[1] && !ft_strcmp("-i", av[1]))
		env = new_env(&av[2], NULL);
	else
		env = new_env(&av[1], env);

	ft_printf("newenv :\n");ft_lstputstr(env);PUTHR
	// ft_lstdel(env);
	// ft_tabdel(av);
	return (OK);
}