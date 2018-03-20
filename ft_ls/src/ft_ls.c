#include "ft_ls.h"

int	get_file(t_env *env, const char *path)
{
	struct dirent	*new_d[BUFF_MAX];
	size_t			i;
	DIR				*dir;

	ft_bzero(new_d, sizeof(new_d));
	if (!(dir = opendir(path)))
		return (FAIL);
	i = 0;
	while ((new_d[i] = readdir(dir)) != NULL)
	{
		if (new_d[i]->d_name[0] != '.' || env->a)
			i++;
		if (env->rup && new_d[i]->d_type == DT_DIR && !(is_pointpoint(new_d[i]->d_name))){
			list_file(env, new_d[i]->d_name);
		}
	}
	env->dir_d = dupdir(new_d);
	closedir(dir);
	return (OK);
}

int		list_file(t_env *env, const char *path)
{
	size_t	i;

	i = 0;
	if ((get_file(env, path)) == FAIL)
		return (FAIL);
	sort_file(env);
	print_list(*env, env->dir_d, path);
	return (OK);
}

int		ft_ls(char **av)
{
	t_env	env;
	size_t	i;

	i = 0;
	if ((init_env(&env, av)) == FAIL)
		return (FAIL);

	print_env(env);
	print_path(env);
	ft_printf("-----------------\n\n");
	while (env.path[i])
	{
		if ((list_file(&env, env.path[i])) == FAIL)
			return (FAIL);
		i++;
	}
	//faire un free/close all
	return (OK);
}