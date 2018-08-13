#include "minishell.h"

void	del_env(t_cli *env)
{
	ft_lstdel(&env->env_var, ft_memdel);
	ft_strdel(&env->pwd);
	ft_memdel((void**)&env);
}

t_cli	*init_env()
{
	extern char	**environ;
	t_cli		*new;

	new = ft_memalloc(sizeof(t_cli));
	new->env_var = ft_artoli(environ);
	new->pwd = get_pwd();
	return (new);
}
