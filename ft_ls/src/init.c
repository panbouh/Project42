#include "ft_ls.h"

t_param	g_paramtab[] =
{
	{'l', &p_l},
	{'r', &p_r},
	{'R', &p_rup},
	{'t', &p_t},
	{'a', &p_a},
	{0, NULL},
};

int		ft_isvalid(char c, char *valid)
{
	size_t	i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (OK);
		i++;
	}
	return (FAIL);
}

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

size_t	init_file(struct dirent **dir_d, t_finfo *f_info, const char *path)
{
	size_t		i;
	size_t		size;

	size = 0;
	i = 0;
	ft_bzero(f_info, sizeof(t_finfo));
	while (dir_d[i])
	{
		if ((stat(ft_newpath(path, dir_d[i]->d_name), &f_info->file_s)) == FAIL)
			return (ft_error("init_file", 0));
		size += f_info->file_s.st_blocks;
		get_max_info(dir_d[i], f_info);
		i++;
	}
	f_info->max_byte = ft_count_digit(f_info->max_byte);
	f_info->max_link = ft_count_digit(f_info->max_link);
	//free newpath
	return (size);
}

int	init_env(t_env *env, char **av)
{
	size_t	i;

	i = 1;
	ft_bzero(env, sizeof(t_env));
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
