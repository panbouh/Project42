// t_month	g_monthtab[] =
// {
// 	{"Jan", 1},
// 	{"Feb", 2},
// 	{"Mar", 3},
// 	{"Apr", 4},
// 	{"May", 5},
// 	{"Jun", 6},
// 	{"Jul", 7},
// 	{"Aug", 8},
// 	{"Sep", 9},
// 	{"Oct", 10},
// 	{"Nov", 11},
// 	{"Dec", 12},
// 	{NULL, 0},
// };

// static int	get_month(char *month)
// {
// 	size_t	i;

// 	i = 0;
// 	while (g_monthtab[i].key)
// 	{
// 		if (!ft_strcmp(month, g_monthtab[i].key))
// 			return (g_monthtab[i].val);
// 		i++;
// 	}
// 	return (-1);
// }

	if (env->f)
		return (lst);
	if (env->r)
	{
		if (env->t)
			return (ft_lstsort(lst, &sort_by_mtime_r));
		else
			return (ft_lstsort(lst, &sort_by_name_r));
	}
	else
	{
		if (env->t)
			return (ft_lstsort(lst, &sort_by_mtime));
		else
			return (ft_lstsort(lst, &sort_by_name));
	}
	return (NULL);

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
char	*get_fmode(mode_t mode)
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
}