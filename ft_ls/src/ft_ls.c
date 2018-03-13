#include "ft_ls.h"


struct dirent **get_file_name(DIR *dir)
{
	struct dirent	*dir_d[12345];
	size_t			i;

	i = 0;
	while ((dir_d[i] = readdir(dir)))
	{
		i++;
	}
	dir_d[i] = NULL;
	return ((struct dirent **)ft_tabdup((void**)dir_d));
}

int		ft_ls(t_env env)
{
	if (!(env.dir = opendir(env.path[0])))
		return (FAIL);
	env.dir_d = get_file_name(env.dir);
	sort_file(&env);
	//faire un free/close all
	return (OK);
}