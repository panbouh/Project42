#include "ft_ls.h"

int		get_one_file(t_maxf *maxf, t_list *new_l, const char *path, char *name)
{
	t_finfo	*f_info;

	if (!(f_info = (t_finfo *)ft_memalloc(sizeof(t_finfo))))
		return (FAIL);
	f_info->name = name;
	if ((get_info(f_info, maxf, ft_newpath(path, f_info->name))) == FAIL)
		return (FAIL);
	ft_lstadd_end(new_l, ft_lstnew_node_m(f_info, sizeof(t_finfo)));
	return (OK);
}

int		get_many_file(t_maxf *maxf, t_list *new_l, const char *path, DIR *dir)
{
	struct dirent	*dir_d;

	maxf->is_dir = 1;
	while ((dir_d = readdir(dir)))
	{
		if (dir_d->d_name[0] != '.' || maxf->a)
			if ((get_one_file(maxf, new_l, path, ft_strdup(dir_d->d_name)))
					== FAIL)
				return (FAIL);
	}
	return (OK);
}

int		check_if_sim(const char *path)
{
	struct stat	bouh;

	if ((lstat(path, &bouh)) == FAIL)
		return (FAIL);
	if (S_ISLNK(bouh.st_mode))
		return (SUCCESS);
	return (OK);
}

int		get_file(t_list *new_l, t_maxf *maxf, const char *path, int l)
{
	DIR		*dir;
	int		ret = OK;

	if (l && (ret = check_if_sim(path)) == SUCCESS)
		return (get_one_file(maxf, new_l, "./", ft_strdup(path)));
	else if (ret == FAIL)
		return (FAIL);
	if (!(dir = opendir(path)))
	{
		if (errno == ENOTDIR)
			return (get_one_file(maxf, new_l, "./", ft_strdup(path)));
		return (FAIL);
	}
	if ((get_many_file(maxf, new_l, path, dir)) == FAIL)
		return (FAIL);
	closedir(dir);
	return (OK);
}