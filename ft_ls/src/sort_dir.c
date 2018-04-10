#include "ft_ls.h"

static void	sort_by_name(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->path[i] && env->path[i + 1])
	{
		if ((ft_strcmp(env->path[i], env->path[i + 1])) > 0)
		{
			ft_memswap((void **)&env->path[i], (void **)&env->path[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

static void	sort_by_name_r(t_env *env)
{
	// size_t	i;

	// i = 0;
	// while (env->path[i] && env->path[i + 1])
	// {
	// 	if ((ft_strcmp(env->path[i], env->path[i + 1])) < 0)
	// 	{
	// 		ft_memswap((void **)&env->path[i], (void **)&env->path[i + 1]);
	// 		i = 0;
	// 	}
	// 	else
	// 		i++;
	// }
}

static void	sort_by_time(t_env *env)
{
// 	size_t		i;

// 	i = 0;
// 	while (env->path[i])
// 	{
// 		if (?)
// 		{
// 			ft_memswap((void **)&env->path[i], (void **)&env->path[i + 1]);
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
}

static void	sort_by_time_r(t_env *env)
{
// 	size_t	i;

// 	i = 0;
// 	while (env->path[i])
// 	{
// 		if (?)
// 		{
// 			ft_memswap((void **)&env->path[i], (void **)&env->path[i + 1]);
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
}

void	sort_dir(t_env *env)
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