#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

char	**get_time(const time_t *t)
{
	char	**last_m;
	char	*bouh;
	//Fri Mar 16 16:25:17 2018
	//16 mar 16:25
	bouh = ctime(t);
	last_m = ft_strsplit(bouh, ' ');
	time_t	now;
	time(&now);
	if (ft_abs(now - *t) > SIX_MONTH)
	{
		last_m[4][ft_strlen(last_m[4]) - 1] = ' ';		//enlever le '\n'
		ft_memswap((void**)&last_m[3], (void**)&last_m[4]);
	}
	return (last_m);
}

char	get_ftype(mode_t m)
{
	if (S_ISREG(m))
		return ('-');
	if (S_ISDIR(m))
		return ('d');
	if (S_ISCHR(m))
		return ('c');
	if (S_ISBLK(m))
		return ('b');
	if (S_ISFIFO(m))
		return ('p');
	if (S_ISLNK(m))
		return ('l');
	if (S_ISSOCK(m))
		return ('s');
	return ('?');
}

char	*get_fmode(mode_t mode)
{
	char	buff[10];

	ft_bzero(buff, sizeof(char) * 10);
	buff[0] = (mode & S_IRUSR) ? 'r' : '-';
	buff[1] = (mode & S_IWUSR) ? 'w' : '-';
	buff[2] = (mode & S_IXUSR) ? 'x' : '-';
	buff[3] = (mode & S_IRGRP) ? 'r' : '-';
	buff[4] = (mode & S_IWGRP) ? 'w' : '-';
	buff[5] = (mode & S_IXGRP) ? 'x' : '-';
	buff[6] = (mode & S_IROTH) ? 'r' : '-';
	buff[7] = (mode & S_IWOTH) ? 'w' : '-';
	buff[8] = (mode & S_IXOTH) ? 'x' : '-';
	if (mode & S_ISVTX)
		buff[8] = (buff[8] == '-' ? 'T' : 't');
	if (mode & S_ISUID)
		buff[2] = (buff[2] == '-' ? 'S' : 's');
	if (mode & S_ISGID)
		buff[5] = (buff[5] == '-' ? 'S' : 's');
	return (ft_strdup(buff));
}

int		get_info(t_finfo *f_info, t_maxf *maxf, char *path)
{
	struct passwd	*file_p;
	struct group	*group_p;

	f_info->path = path;
	// ft_printf("path = %s\n", path);
	// ft_printf("name : %s\n", f_info->name);
	if((lstat(path, &f_info->file_s)) == FAIL)
		return (FAIL);
	maxf->bsize += f_info->file_s.st_blocks;
	errno = 0;

	if (!(file_p = getpwuid(f_info->file_s.st_uid)))
		f_info->uidname = ft_itoa(f_info->file_s.st_uid);
	else
		f_info->uidname = ft_strdup(file_p->pw_name);
	//-------------------------------------------------------
	if(!(group_p = getgrgid(f_info->file_s.st_gid)))
		f_info->gidname = ft_itoa(f_info->file_s.st_gid);
	else
		f_info->gidname = ft_strdup(group_p->gr_name);

	f_info->mode = get_fmode(f_info->file_s.st_mode);
	f_info->type = get_ftype(f_info->file_s.st_mode);
	f_info->time = get_time(&f_info->file_s.st_mtime);

	f_info->size = get_size(f_info);
	get_max(f_info, maxf);
	return (OK);
}