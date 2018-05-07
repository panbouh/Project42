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
	ft_tabdel((void**)f_info->time);
}

void	delall(t_list *lst)
{
	t_finfo	*f_info;

	while (lst->node)
	{
		delfinfo(lst->node->data);
		lst->node = lst->node->next;
	}
	ft_lstdel(&lst);
}

/*
	char			*name;
	char			*path;
	char			*uidname;
	char			*gidname;
	char			*mode;
	char			*size;
	unsigned char	type;
	struct stat		file_s;
	char			**time;

*/