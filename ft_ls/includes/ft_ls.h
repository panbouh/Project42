#ifndef FT_LS_H
# define FT_LS_H

#include "libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <unistd.h>

typedef	struct	s_param
{
	char	key;
	void	(*f)();
}				t_param;

typedef	struct	s_env
{
	char			l;
	char			r;
	char			rup;
	char			t;
	char			a;
	char			**path;
	struct dirent	**dir_d;
	struct stat		**file_s;
	DIR				*dir;
}				t_env;

/*
** ft_ls.c
*/
int				ft_ls(char **av);

/*
** print.c
*/
void	print_dir(struct dirent **dir_d);


/*
** init.c
*/
struct dirent **get_file(DIR *dir);
void	check_param(t_env *env)
t_env	*init_env(char **av, t_env *env);

/*
** sorting.c
*/
void	sort_file(t_env *env);
void	sort_by_name_r(t_env *env);
void	sort_by_name(t_env *env);
void	sort_by_time(t_env *env);
void	sort_by_time_r(t_env *env);


/*
** paran.c
*/
void	p_l(t_env *env);
void	p_r(t_env *env);
void	p_rup(t_env *env);
void	p_t(t_env *env);
void	p_a(t_env *env);


#endif
