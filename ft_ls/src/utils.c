#include "ft_ls.h"

int		is_pointpoint(char *dir)
{
	if (!ft_strcmp(dir, ".") || !ft_strcmp(dir, ".."))
		return (1);
	return (0);
}

void	delfinfo(t_finfo *f_info)
{
	ft_strdel(&f_info->name);
	ft_strdel(&f_info->path);
	ft_strdel(&f_info->uidname);
	ft_strdel(&f_info->gidname);
	ft_strdel(&f_info->mode);
	ft_strdel(&f_info->size);
	ft_tabsdel(f_info->time);
}

void	delall(t_list *lst)
{
	t_finfo	*f_info;
	lst->node = lst->first;
	while (lst->node)
	{
		delfinfo(lst->node->data);
		lst->node = lst->node->next;
	}
	ft_lstdel(&lst);
}

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
	return (new);
}