#include "ft_ls.h"

t_list *get_one_file(t_maxf *maxf, t_list *new_l, const char *path, char *name)
{
	t_finfo	*f_info;

	if (!(f_info = (t_finfo *)ft_memalloc(sizeof(t_finfo))))
		return (NULL);
	f_info->name = name;
	get_info(f_info, maxf, ft_newpath(path, f_info->name));
	ft_lstadd_end(new_l, ft_lstnew_node(f_info, sizeof(t_finfo)));
	//newpatj
	return (new_l);
}

t_list	*get_file(t_maxf *maxf, const char *path, int a)
{
	t_list			*new_l;
	t_finfo			*f_info;
	char			*tmp;
	struct dirent	*dir_d;
	DIR				*dir;

	new_l = ft_lstnew();
	if (!(dir = opendir(path)))
	{
		if (errno == ENOTDIR)
			return (get_one_file(maxf, new_l, "./", (char *)path));
		return (NULL);
	}
	maxf->is_dir = 1;
	while ((dir_d = readdir(dir)))
	{
		ft_printf("name : %s, ino = %li\n", dir_d->d_name, dir_d->d_ino);
		if (dir_d->d_name[0] != '.' || a)
			if (!(new_l = get_one_file(maxf, new_l, path,
										ft_strdup(dir_d->d_name))))
				return (NULL);
	}
	closedir(dir);
	//freeall
	return (new_l);
}

void	list_r(t_env *env, t_list *lst, const char *path)
{
	char	*new_p;

	while (lst->node)
	{
		if (((t_finfo*)lst->node->data)->type == 'd')
		{
			new_p = ft_newpath(path, ((t_finfo*)lst->node->data)->name);
			ft_printf("\n%s:\n", new_p);
			list_file(env, new_p);
		}
		lst->node = lst->node->next;
	}
}

int		list_file(t_env *env, const char *path)
{
	t_list	*lst;
	t_maxf	maxf;

	errno = 0;
	// ft_printf("path = %s\n", path);
	ft_bzero(&maxf, sizeof(t_maxf));
	if (!(lst = get_file(&maxf, path, env->a)))
		return (err(path, strerror(errno), FAIL));
	// lstput(lst, "Origin");
	// ft_printf("avant : %p\n", lst);
	t_list	*tmp = lst;
	lst = sort_file(env, lst);
	// ft_printf("apres : %p, tmp = %p\n", lst, tmp);
	// ft_printf("tmp->node : %p\n", ((t_finfo*)tmp->node)->name);
	// ft_printf("lst->node : %p\n", ((t_finfo*)lst->node)->name);
	// lstput(lst, "\n-----\nDorted");
	if (lst->node)
		print_list(env, lst, &maxf);
	if (env->rup)
		list_r(env, lst, path);
	//freeall
	return (OK);
}

int		ft_ls(char **av)
{
	t_env	env;
	size_t	i;

	i = 0;
	if ((init_env(&env, av)) == FAIL)
		return (FAIL);

	// print_env(env);
	// print_path(env);
	// ft_printf("-----------------\n\n");
	while (env.path[i])
	{
		if (ft_tablen(env.path) > 1)
			ft_printf("%s:\n", env.path[i]);
		if ((list_file(&env, env.path[i])) == FAIL)
			err(env.path[i], strerror(errno), FAIL);
		i++;
	}
	//faire un free/close all
	return (OK);
}