#include "ft_ls.h"

char	*ft_newpath(const char *path, const char *name)
{
	char	new[BUFF_MAX];
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	ft_bzero(new, BUFF_MAX);
	while (path[x])
	{
		new[i] = path[x];
		if (path[x] == '/')
			x = ft_skip_char(path, x, '/', ALL);
		else
			x++;
		i++;
	}
	if (new[i - 1] && new[i - 1] != '/')
		new[i++] = '/';
	ft_strcpy(&new[i], name);
	i += ft_strlen(name);
	new[i] = 0;
	return (ft_strdup(new));
}

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