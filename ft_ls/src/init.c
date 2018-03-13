#include "ft_ls.h"

t_test	g_tab[] =
{
	{'l', &p_l},
	{'r', &p_r},
	{'R', &p_rup},
	{'t', &p_t},
	{'a', &p_a},
	{0, NULL},
};

void	init_param(t_env *env, size_t x, char **tab)
{
	size_t	i;
	size_t	size;

	size = ft_tablen((const char**)tab);
	i = 0;
	if (x)
	{
		env->path = (char **)malloc(sizeof(char *) * size);
		env->file_s = (struct stat **)malloc(sizeof(struct stat *) * size);
		while (env->path[i])
		{
			env->path[i] = tab[i];
			stat(env->dir_d[i]->d_name, env->file_s[i]);
			i++;
		}
	}
	else
	{
		env->path = (char **)malloc(sizeof(char *) * 2);
		env->path[0] = ft_strdup(".");
		env->path[1] = NULL;
	}
}

t_env	*get_param(char **av, t_env *env)
{
	size_t	y;
	size_t	i;
	size_t	x;
	char	*tab[12345];

	y = 1;
	x = 0;
	while (av[y])
	{
		i = 0;
		if (av[y][0] == '-')
			while (g_tab[i].key)
			{
				if (g_tab[i].key == av[y][1])
					g_tab[i].f(env);
				i++;
			}
		else
			tab[x++] = av[y];
		y++;
	}
	init_param(env, x, tab);
	return (env);
}
