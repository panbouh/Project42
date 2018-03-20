#include "ft_ls.h"

static void	sort_by_name(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->dir_d[i] && env->dir_d[i + 1])
	{
		if ((ft_strcmp(env->dir_d[i]->d_name, env->dir_d[i + 1]->d_name)) > 0)
		{
			ft_memswap((void **)&env->dir_d[i], (void **)&env->dir_d[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

static void	sort_by_name_r(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->dir_d[i] && env->dir_d[i + 1])
	{
		if ((ft_strcmp(env->dir_d[i]->d_name, env->dir_d[i + 1]->d_name)) < 0)
		{
			ft_memswap((void **)&env->dir_d[i], (void **)&env->dir_d[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

static void	sort_by_time(t_env *env)
{
	// size_t		i;

	// i = 0;
	// while (env->dir_d[i])
	// {
	// 	if (env->file_s[i].st_size > env->file_s[i].st_size)
	// 	{
	// 		ft_memswap((void **)&env->dir_d[i], (void **)&env->dir_d[i + 1]);
	// 		i = 0;
	// 	}
	// 	else
	// 		i++;
	// }
	// print_dir(*env);
}

static void	sort_by_time_r(t_env *env)
{
	// size_t	i;

	// i = 0;
	// while (env->dir_d[i])
	// {
	// 	if (env->dir_d[i + 1] && env->dir_d[i]->d_name[0] > env->dir_d[i + 1]->d_name[0])
	// 	{
	// 		ft_memswap((void **)&env->dir_d[i], (void **)&env->dir_d[i + 1]);
	// 		i = 0;
	// 	}
	// 	else
	// 		i++;
	// }
	// print_dir(*env);
}


void	sort_file(t_env *env)
{
	if (env->t)
	{
		if (env->r)
			sort_by_time_r(env);
		else
			sort_by_time(env);
	}
	else if (env->r)
		sort_by_name_r(env);
	else
		sort_by_name(env);
}