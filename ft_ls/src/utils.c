#include "ft_ls.h"

int		is_pointpoint(char *dir)
{
	if (!ft_strcmp(dir, ".") || !ft_strcmp(dir, ".."))
		return (1);
	return (0);
}

void	delfinfo(void **f_info)
{
	t_finfo	*tmp;

	tmp = *f_info;
	ft_strdel(&tmp->name);
	ft_strdel(&tmp->path);
	ft_strdel(&tmp->uidname);
	ft_strdel(&tmp->gidname);
	ft_strdel(&tmp->mode);
	ft_strdel(&tmp->size);
	ft_tabsdel(tmp->time);
}

// void	delall(t_list *lst)
// {
// 	t_finfo	*f_info;
// 	lst->node = lst->first;
// 	while (lst->node)
// 	{
// 		delfinfo(lst->node->data);
// 		lst->node = lst->node->next;
// 	}
// 	ft_lstdel(&lst);
// }

char	*get_onlypath(char *path)
{
	char	new[BUFF_MAX];
	// size_t	i;
	int		stop;

	ft_bzero(&new, BUFF_MAX);
	// i = 0;
	stop = ft_strlen(path) - 1;
	while (stop >= 0 && path[stop] != '/')
		stop--;
	ft_strncat(new, path, stop);
	return (ft_strdup(new));
}