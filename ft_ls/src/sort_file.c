#include "ft_ls.h"

	// ((t_finfo*)lst->content)->name

t_list	*merge(t_list *lst_l, t_list *lst_r)
{
	t_list	*result;

	result = ft_lstnew(); //malloc
	while (lst_l->node && lst_r->node)
	{
		if (ft_strcmp(((t_finfo*)lst_l->node->data)->name,
						((t_finfo*)lst_r->node->data)->name) > 0)
		{
			ft_lstadd_end(result, lst_r->node); //malloc
			lst_r->node = lst_r->node->next;
		}
		else
		{
			ft_lstadd_end(result, lst_l->node); //malloc
			lst_l->node = lst_l->node->next;
		}
	}
	result = ft_lstcat(result, lst_l);
	result = ft_lstcat(result, lst_r);
	return (result);
}

static t_list	*sort_by_name(t_env *env, t_list *lst)
{
	t_list	*lst_r;
	t_list	*lst_l;
	size_t	size;

	if ((size = lst->size) <= 1)
		return (lst);
	lst_l = ft_lstsub(lst, 0, size / 2); //malloc
	lst_r = ft_lstsub(lst, size / 2, (size - size / 2)); //malloc
	ft_lstdel(&lst);
	lst_l = sort_by_name(env, lst_l);
	lst_r = sort_by_name(env, lst_r);
	return (merge(lst_l, lst_r));  //malloc
}







































static void	sort_by_name_r(t_env *env, t_list *lst)
{

}

static void	sort_by_time(t_env *env, t_list *lst)
{

}

static void	sort_by_time_r(t_env *env, t_list *lst)
{

}


t_list	*sort_file(t_env *env, t_list *lst)
{
	if (env->t)
	{
		if (env->r)
			sort_by_time_r(env, lst);
		else
			sort_by_time(env, lst);
	}
	else if (env->r)
		sort_by_name_r(env, lst);
	else
		return (sort_by_name(env, lst));
	return (NULL);
}