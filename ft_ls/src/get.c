#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

t_type	g_typetab[] =
{
	{DT_REG, '-'},
	{DT_DIR, 'd'},
	{DT_LNK, 'l'},
	{DT_BLK, 'b'},
	{DT_SOCK, 's'},
	{DT_CHR, 'c'},
	{DT_FIFO, 'p'},
	{DT_UNKNOWN, '?'},
	{0, 0},
};

t_right	g_righttab[] =
{
	{'7', "rwx"},
	{'6', "rw-"},
	{'5', "r-x"},
	{'4', "r--"},
	{'3', "-wx"},
	{'2', "-w-"},
	{'1', "--x"},
	{0, NULL},
};

char	**get_time(struct stat file_s)
{
	char	buff[BUFF_MAX];
	char	**last_m;
	//Fri Mar 16 16:25:17 2018
	//16 mar 16:25
	last_m = ft_strsplit(ctime(&file_s.st_mtime), ' ');
	return (last_m);
}

char	get_ftype(unsigned char c)
{
	char	type;
	size_t	i;

	i = 0;
	while (g_typetab[i].key)
	{
		if (g_typetab[i].key == c)
			return (g_typetab[i].type);
		i++;
	}
	return (0);
}

char	*get_fmode(unsigned int n)
{
	char	buff[BUFF_MAX];
	char	*mode;
	size_t	size;
	size_t	i;
	size_t	x;
	size_t	y;

	mode = ft_conv_nbase(n, 8);
	size = ft_strlen(mode);
	i = size - 4;
	y = 0;
	while (mode[i])
	{
		x = 0;
		while(g_righttab[x].key)
		{
			if (g_righttab[x].key == mode[i])
				ft_strcat(buff, g_righttab[x].right);
			x++;
		}
		i++;
		y += 3;
	}
	buff[y] = 0;
	return (ft_strdup(buff));
}

int		get_max_info(struct dirent *dir_d, t_finfo *f_info)
{
	size_t		i;
	size_t		uname;
	size_t		name;
	size_t		grou;

	f_info->file_p = getpwuid(f_info->file_s.st_uid);
	f_info->group_p = getgrgid(f_info->file_s.st_gid);
	i = 0;
	uname = ft_strlen(f_info->file_p->pw_name);
	grou = ft_strlen(f_info->group_p->gr_name);
	name = ft_strlen(dir_d->d_name);
	if (f_info->max_byte < f_info->file_s.st_size)
		f_info->max_byte = f_info->file_s.st_size;
	// ft_printf("max byte = %i\n", f_info->max_byte);
	if (f_info->max_link < f_info->file_s.st_nlink)
		f_info->max_link = f_info->file_s.st_nlink;
	i++;
	if (f_info->max_uname < uname)
		f_info->max_uname = uname;
	if (f_info->max_gr < grou)
		f_info->max_gr = grou;
	if (f_info->max_name < name)
		f_info->max_name = name;
	return (OK);
}
