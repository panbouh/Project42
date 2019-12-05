#include "minishell.h"
#include "ft_printf.h"

t_list			*new_env(char **av, t_list *old)
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

static char 	**init_skip()
{
	char	**new;

	new = malloc(sizeof(char *) * 3);
	new[0] = ft_strdup("=");
	new[1] = ft_strdup("-i");
	new[2] = 0;
	return (new);
}

int				bul_env(char **av, t_list *env)
{
	char	**tab_skip;
	char	**new_av;
	char	ret;

	ret = OK;
	if (!av[1])
	{
		ft_lstputstr(env);
		return (OK);
	}
	if (av[1] && !ft_strcmp("-i", av[1]))
		env = new_env(&av[2], NULL);
	else
		env = new_env(&av[1], env);
	tab_skip = init_skip();
	new_av = ft_tabtskip(&av[1], tab_skip);
	ft_tabsdel(tab_skip);
	if (new_av)
		ret = a_out(new_av, env);
	else
		ft_lstputstr(env);
	ft_lstdel(&env, &del_env);
	return (OK);
}