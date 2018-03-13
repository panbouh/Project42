#ifndef FT_LS_H
# define FT_LS_H

#include "libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <unistd.h>

typedef	struct	s_test
{
	char	key;
	void	(*f)();
}				t_test;

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
** libft.c
*/
char	**ft_tabcpy(char **src, char **dest);
void	**ft_tabdup(void **src);
void	ft_memswap(void *a, void *b);
void	**ft_tabdel(void **tab);


/*
** ft_ls.c
*/
struct dirent	**get_file_name(DIR *dir);
int				ft_ls(t_env env);

/*
** print.c
*/
void	print_dir(struct dirent **dir_d);


/*
** init.c
*/
t_env	*get_param(char **av, t_env *env);

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
