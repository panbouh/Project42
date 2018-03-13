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

struct dirent **get_file(DIR *dir)
{
	struct dirent	*dir_d[12345];
	size_t			i;

	i = 0;
	while ((dir_d[i] = readdir(dir)))
		i++;
	dir_d[i] = NULL;
	return ((struct dirent **)ft_tabdup((void**)dir_d));
}

void	check_param(t_env *env)
{
	size_t	i;

	i = 0;
	while (g_paramtab[i].key)
	{
		if (g_paramtab[i].key == ??)
			g_paramtab[i].f(??);
		i++;
	}
}

void	init_path()
{
	
}

void	init_env(char **av, t_env *env)
{

	if (!(env.dir = opendir(env.path[0])))
		return (FAIL);
	env.dir_d = get_file(env.dir);

}
