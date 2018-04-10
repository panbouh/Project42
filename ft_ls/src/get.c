#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

t_mode	g_modetab[] =
{
	{'7', "rwx"},
	{'6', "rw-"},
	{'5', "r-x"},
	{'4', "r--"},
	{'3', "-wx"},
	{'2', "-w-"},
	{'1', "--x"},
	{'0', "---"},
	{0, NULL},
};

char	**get_time(const time_t *t)
{
	char	**last_m;
	//Fri Mar 16 16:25:17 2018
	//16 mar 16:25
	last_m = ft_strsplit(ctime(t), ' ');
	time_t	now;
	time(&now);
	if (ft_abs(now - *t) > SIX_MONTH)
	{
		last_m[4][ft_strlen(last_m[4]) - 1] = 0;
		last_m[3] = last_m[4];
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

char	*get_fmode(mode_t m)
{
	char	buff[BUFF_MAX];
	char	*mode;
	size_t	size;
	size_t	i;
	size_t	x;

	mode = ft_conv_nbase(m, 8);
	size = ft_strlen(mode);
	i = size - 3;
	ft_bzero(&buff, BUFF_MAX);
	while (mode[i])
	{
		x = 0;
		while(g_modetab[x].key)
		{
			if (g_modetab[x].key == mode[i])
				ft_strcat(buff, g_modetab[x].mode);
			x++;
		}
		i++;
	}
	buff[9] = 0;
	ft_strdel(&mode);
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
		return (ft_error("err getinfo : stat fail", errno));
	ft_printf("ino : %li\n", f_info->file_s.st_ino);
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