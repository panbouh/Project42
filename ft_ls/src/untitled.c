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