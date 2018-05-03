#include "ft_ls.h"

void	p_t(t_env *env)
{
	env->t = 1;
	env->tsize++;
	if (env->tsize > NB_SORT_P)
		return ;
	ft_strcat(env->tab_sort, "t\0");
}

/*
**	BONUS
*/

void	p_u(t_env *env)
{
	env->u = 1;
	env->tsize++;
	if (env->tsize > NB_SORT_P)
		return ;
	ft_strcat(env->tab_sort, "u\0");
}

void	p_c(t_env *env)
{
	env->c = 1;
	env->tsize++;
	if (env->tsize > NB_SORT_P)
		return ;
	ft_strcat(env->tab_sort, "c\0");
}

void	p_f(t_env *env)
{
	env->f = 1;
	env->tsize++;
	if (env->tsize > NB_SORT_P)
		return ;
	ft_strcat(env->tab_sort, "f\0");
}

void	p_sup(t_env *env)
{
	env->sup = 1;
	env->tsize++;
	if (env->tsize > NB_SORT_P)
		return ;
	ft_strcat(env->tab_sort, "S\0");
}
