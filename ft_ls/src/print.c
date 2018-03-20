#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

int		print_info(struct dirent *dir_d, t_finfo f_info, const char *path)
{
	if ((stat(path, &f_info.file_s)) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	//info system
	f_info.file_p = getpwuid(f_info.file_s.st_uid);
	f_info.group_p = getgrgid(f_info.file_s.st_gid);
	f_info.time = get_time(f_info.file_s);
	//calcul
	f_info.type = get_ftype(dir_d->d_type);
	f_info.mode = get_fmode(f_info.file_s.st_mode);
	// ft_printf("adaw = %i\n", f_info.max_name);
	ft_printf("%c%s  %*i %*s  %*s  %*li %*s %s %.*s %s\n",
		f_info.type,
		f_info.mode,
		f_info.max_link , f_info.file_s.st_nlink,
		f_info.max_uname, f_info.file_p->pw_name,
		f_info.max_gr, f_info.group_p->gr_name,
		f_info.max_byte, f_info.file_s.st_size,
		2, f_info.time[2],
		ft_strlower(f_info.time[1]),
		5, f_info.time[3],
		dir_d->d_name);
	//free all
	return (OK);
}

void	print_list(t_env env, struct dirent **dir_d, const char *path)
{
	size_t		i;
	size_t		size_b;
	t_finfo		f_info;

	i = 0;
	size_b = init_file(dir_d, &f_info, path);
	// ft_printf("max = %i\n", f_info.max_name);
	if (env.l)
		ft_printf("total : %i\n", size_b);
	while (dir_d[i])
	{
		if (env.l)
			print_info(dir_d[i], f_info, ft_newpath(path, dir_d[i]->d_name));
		else
			ft_putendl(dir_d[i]->d_name);
		i++;
	}
	//add del dir newpath
}