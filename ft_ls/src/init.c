#include "ft_ls.h"

t_param	g_paramtab[] =
{
	{'l', &p_l},
	{'R', &p_rup},
	{'a', &p_a},
	{'r', &p_r},
	{'t', &p_t},
	{'u', &p_u},
	{'c', &p_c},
	{'S', &p_sup},
	{'f', &p_f},
	{0, NULL},
};

int	lanormeomg(t_env *env, char *param)
{
	size_t	x;
	size_t	i;

	x = 1;
	while (param[x] && !env->stop)
	{
		i = 0;
		if ((ft_isvalid(param[x], ALL_PARAM)) == FAIL)
			return (err_invalid_param(env, param[x]));
		while (g_paramtab[i].key)
		{
			if (g_paramtab[i].key == param[x])
			{
				g_paramtab[i].f(env);
				break;
			}
			i++;
		}
		x++;
	}
	return (OK);
}

int	check_param(t_env *env, char **av, size_t *y)
{
	while (av[*y] && av[*y][0] && av[*y][0] == '-' && !env->stop)
	{
		if (!ft_strcmp(av[*y], "--"))
			env->stop = 1;
		if (!av[*y][1])
			return (OK);
		if ((lanormeomg(env, av[*y])) == FAIL)
			return (FAIL);
		(*y)++;
	}
	return (OK);
}

int	init_env(t_env *env, char **av)
{
	size_t	i;

	i = 1;
	ft_bzero(env, sizeof(*env));
	if ((check_param(env, av, &i)) == FAIL)
		return (FAIL);
	if (av[i])
	{
		env->path = ft_tabsdup(&av[i]);
		sort_dir(env);
	}
	else
	{
		env->path = malloc(sizeof(char**) * 2);
		env->path[0] = ft_strdup(".");
		env->path[1] = NULL;
	}
	return (OK);
}
