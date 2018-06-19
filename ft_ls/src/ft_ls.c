#include "ft_ls.h"

void	list_r(t_env *env, t_list *lst, const char *path)
{
	char	*new_p;

	while (lst->node)
	{
		if (((t_finfo*)lst->node->data)->type == 'd'
			&& ft_strcmp(((t_finfo*)lst->node->data)->name, ".")
			&& ft_strcmp(((t_finfo*)lst->node->data)->name, ".."))
		{
			new_p = ft_newpath(path, ((t_finfo*)lst->node->data)->name);
			if ((ft_tablen(env->path)) <= 1)
				ft_printf("\n%s:", new_p);
			ft_putchar('\n');
			list_file(env, new_p);
			ft_strdel(&new_p);
		}
		lst->node = lst->node->next;
	}
}

int		list_file(t_env *env, const char *path)
{
	t_list	*lst;
	t_maxf	maxf;
	int		ret;

	lst = ft_lstnew();
	ft_bzero(&maxf, sizeof(t_maxf));
	if (env->a)
		maxf.a = 1;
	if ((ret = get_file(lst, &maxf, path, env->l)) != FAIL)
	{
		if (!(lst = sort_file(env, lst)))
			return (FAIL);
		if (lst->node)
			print_list(env, lst, &maxf);
		if (env->rup)
			list_r(env, lst, path);
	}
	BOUH
	ft_lstdel(&lst, &delfinfo);
	return (ret);
}

int		ft_ls(char **av)
{
	t_env	env;
	size_t	i;
	size_t	ret;

	i = 0;
	if ((init_env(&env, av)) == FAIL)
		return (FAIL);

	// print_env(env);
	// print_path(env);
	// ft_printf("-----------------\n\n");
	while (env.path[i])
	{
		// if (ft_tablen(env.path) > 1)		//pas ici ><
		// 	ft_printf("%s:\n", env.path[i]);
		if ((ret = (list_file(&env, env.path[i]))) == FAIL)
			err(env.path[i], strerror(errno), FAIL);
		i++;
		if (env.path[i] && ret != FAIL)
			ft_putstr("\n");
	}
	ft_tabsdel(env.path);
	//faire un free/close all
	return (OK);
}