#include "ft_ls.h"
#include <time.h>

t_sorting	g_sorttab[] =
{
	{'t', &sort_by_mtime},
	{'u', &sort_by_atime},
	{'c', &sort_by_ctime},
	{'S', &sort_by_size},
	{0, NULL},
};

t_sorting	g_sorttab_r[] =
{
	{'t', &sort_by_mtime_r},
	{'u', &sort_by_atime_r},
	{'c', &sort_by_ctime_r},
	{'S', &sort_by_size_r},
	{0, NULL},
};

int	sort_by_name(t_node *nd1, t_node *nd2)
{
	if ((ft_strcmp(((t_finfo*)nd1->data)->name,
					((t_finfo*)nd2->data)->name)) < 0)
		return (0);
	return (1);
}

int	sort_by_name_r(t_node *nd1, t_node *nd2)
{
	if ((ft_strcmp(((t_finfo*)nd1->data)->name,
					((t_finfo*)nd2->data)->name)) < 0)
		return (1);
	return (0);
}

int	sort_by_mtime(t_node *nd1, t_node *nd2)
{
	time_t	t1;
	time_t	t2;

	t1 = ((t_finfo*)nd1->data)->file_s.st_mtime;
	t2 = ((t_finfo*)nd2->data)->file_s.st_mtime;
	if (t1 < t2)
		return (1);
	return (0);
}

int	sort_by_mtime_r(t_node *nd1, t_node *nd2)
{
	time_t	t1;
	time_t	t2;

	t1 = ((t_finfo*)nd1->data)->file_s.st_mtime;
	t2 = ((t_finfo*)nd2->data)->file_s.st_mtime;
	if (t1 >= t2)
		return (1);
	return (0);
}


t_list	*sort_file(t_env *env, t_list *lst)
{
	size_t	i;

	i = 0;
	if (env->r && !env->f)
	{
		while (g_sorttab_r[i].key)
		{
			if (ft_strchr(env->tab_sort, g_sorttab_r[i].key))
				return (ft_lstsort(lst, g_sorttab_r[i].f, &delfinfo));
			i++;
		}
		return (ft_lstsort(lst, &sort_by_name_r, &delfinfo));
	}
	else if (!env->f)
	{
		while (g_sorttab[i].key)
		{
			if (ft_strchr(env->tab_sort, g_sorttab[i].key))
				return (ft_lstsort(lst, g_sorttab[i].f, &delfinfo));
			i++;
		}
		return (ft_lstsort(lst, &sort_by_name, &delfinfo));
	}
	return (lst);
}