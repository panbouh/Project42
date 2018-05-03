#include "ft_ls.h"

static void	sort_by_name_d(t_env *env)
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

static void	sort_by_name_dr(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->path[i] && env->path[i + 1])
	{
		if ((ft_strcmp(env->path[i], env->path[i + 1])) < 0)
		{
			ft_memswap((void **)&env->path[i], (void **)&env->path[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	sort_dir(t_env *env)
{
	if (env->r)
		sort_by_name_dr(env);
	else
		sort_by_name_d(env);
}