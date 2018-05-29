#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

int		print_info(t_list *lst, t_maxf *maxf)
{
	char	buff[BUFF_MAX];
	size_t	size;

	ft_printf("%c%s  %*i %*-s  %*-s  %*s %*s %s %*.*s %s",
		((t_finfo*)lst->node->data)->type,
		((t_finfo*)lst->node->data)->mode,
		maxf->link , ((t_finfo*)lst->node->data)->file_s.st_nlink,
		maxf->uname, ((t_finfo*)lst->node->data)->uidname,
		maxf->grname, ((t_finfo*)lst->node->data)->gidname,
		//--------------------------------------------------------
		maxf->byte, ((t_finfo*)lst->node->data)->size,
		//maxf->byte, ((t_finfo*)lst->node->data)->file_s.st_size,
		2, ((t_finfo*)lst->node->data)->time[2],
		ft_strlower(((t_finfo*)lst->node->data)->time[1]),
		5, 5, ((t_finfo*)lst->node->data)->time[3],
		((t_finfo*)lst->node->data)->name);
	if (((t_finfo*)lst->node->data)->type == 'l')
	{
		size = readlink(((t_finfo*)lst->node->data)->path, buff, BUFF_MAX);
		buff[size] = 0;
		ft_printf(" -> %s", buff);
	}
	ft_putchar('\n');
	//free all
	return (OK);
}

void	print_list(t_env *env, t_list *lst, t_maxf *maxf)
{
	char	*path = get_onlypath(((t_finfo*)lst->node->data)->path);
	if (((ft_tablen(env->path)) > 1 && maxf->is_dir))
			ft_printf("%s:\n", path); //afficher juste le nom du dosier avant
	if (env->l && maxf->is_dir)
		ft_printf("total %i\n", maxf->bsize);
	while (lst->node)
	{
		if (env->l)
			print_info(lst, maxf);
		else
			ft_putendl(((t_finfo*)lst->node->data)->name);
		lst->node = lst->node->next;
	}
	lst->node = lst->first;
	ft_strdel(&path);
}