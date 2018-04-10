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

	size_t	i;
	t_list *next;
	t_list *tmp;

	if (!lst)
		return ;
	tmp = lst;
	next = lst->next;
	i = 0;
	while (lst && next)
	{
		if ((ft_strcmp(((t_finfo*)lst->content)->name, ((t_finfo*)next->content)->name)) > 0)
		{
			ft_lstswap(lst, next);
			lst = tmp;
			next = tmp->next;
		}
		else
		{
			lst = lst->next;
			next = next->next;
		}
	}


			if (ft_strcmp(((t_finfo*)lst_l->node->data)->name,
						((t_finfo*)lst_r->node->data)->name) > 0)
		{
			ft_lstadd_end(result,
				ft_lstnew_node(lst_r->node->data, lst_r->node->data_size)); //malloc
			lst_r->node = lst_r->node->next;
		}
		else
		{
			ft_lstadd_end(result,
				ft_lstnew_node(lst_l->node->data, lst_l->node->data_size)); //malloc
			lst_l->node = lst_l->node->next;
		}