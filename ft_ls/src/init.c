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

int	check_param(t_env *env, char **av, size_t *y)
{
	size_t	i;
	size_t	x;

	while (av[*y] && av[*y][0] && av[*y][0] == '-')
	{
		x = 1;
		while (av[*y][x])
		{
			i = 0;
			if ((ft_isvalid(av[*y][x], ALL_PARAM)) == FAIL)
				return (err_invalid_param(env, av[*y][x]));
			while (g_paramtab[i].key)
			{
				if (g_paramtab[i].key == av[*y][x])
					g_paramtab[i].f(env);
				i++;
			}
			x++;
		}
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
		env->path = &av[i];
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
