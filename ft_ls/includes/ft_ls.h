#ifndef FT_LS_H
# define FT_LS_H

#include "libft.h"
#include "ft_list.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <errno.h>
#include <string.h>

# define	ALL_PARAM	"RalrtucSf"
# define	USE			"usage: ft_ls [-RalrtucSf] [file ...]\0"
# define	INV_PAR		"ft_ls: illegal option -- \0"
# define	ONE_DAY		86400
# define	SIX_MONTH	(ONE_DAY * 30) * 3 + (ONE_DAY * 31) * 3
# define	NB_SORT_P	6

typedef struct	s_param
{
	char	key;
	void	(*f)();
}				t_param;

typedef struct	s_sorting
{
	char	key;
	int		(*f)(t_node*, t_node*);
}				t_sorting;

// typedef struct	s_error
// {
// 	int		key;
// 	void	(*f)();
// }				t_error;

// typedef struct	s_mode
// {
// 	char	key;
// 	char	*mode;
// }				t_mode;

typedef struct	s_month
{
	char	*key;
	int		val;
}				t_month;

typedef struct	s_env
{
	char			**path;
	char			tab_sort[NB_SORT_P];	//sort option
	int				tsize;
	char			stop;
	char			l;
	char			rup;
	char			a;
	char			t;			//mtime
	char			u;			//atime
	char			c;			//ctime
	char			f;			//no tri
	char			sup;		//size
	char			r;			//reverse
}				t_env;

typedef struct	s_finfo
{
	char			*name;
	char			*path;
	char			*uidname;
	char			*gidname;
	char			*mode;
	char			*size;
	unsigned char	type;
	struct stat		file_s;
	char			**time;
}				t_finfo;

typedef struct	s_maxf
{
	char			a;
	size_t			bsize;
	size_t			name;
	size_t			uname;
	size_t			grname;
	size_t			link;
	size_t			byte;
	size_t			is_dir;
}				t_maxf;

/*
** ft_ls.c
*/
void			list_r(t_env *env, t_list *lst, const char *path);
int				list_file(t_env *env, const char *path);
int				ft_ls(char **av);

/*
** get_file.c
*/
int				get_one_file(t_maxf *maxf, t_list *new_l, const char *path,
								char *name);
int				get_many_file(t_maxf *maxf, t_list *new_l, const char *path,
								DIR *dir);
int				check_if_sim(const char *path);
int				get_file(t_list *lst, t_maxf *maxf, const char *path, int l);

/*
** print.c
*/
int				print_info(t_list *lst, t_maxf *maxf);
void			print_list(t_env *env, t_list *lst, t_maxf *maxf);


/*
** ultils.c
*/
void			delfinfo(t_finfo *f_info);
void			delall(t_list *lst);
char			*ft_newpath(const char *path, const char *name);
int				is_pointpoint(char *dir);
char			*get_onlypath(char *path);

/*
** get.c
*/
int				get_info(t_finfo *f_info, t_maxf *maxf, char *path);
char			**get_time(const time_t *t);
char			*get_fmode(mode_t m);
char			get_ftype(mode_t mode);
/*
** get2.c
*/
char			*get_size(t_finfo *f_info);
int				get_max(t_finfo *f_info, t_maxf *maxf);

/*
** init.c
*/
int				check_param(t_env *env, char **av, size_t *y);
int				init_env(t_env *env, char **av);

/*
** sorting.c
*/
t_list			*sort_file(t_env *env, t_list *lst);
void			sort_dir(t_env *env);
int				sort_by_name(t_node *nd1, t_node *nd2);
int				sort_by_name_r(t_node *nd1, t_node *nd2);
int				sort_by_mtime(t_node *nd1, t_node *nd2);
int				sort_by_mtime_r(t_node *nd1, t_node *nd2);


/*
** param.c
*/
void			p_l(t_env *env);
void			p_rup(t_env *env);
void			p_a(t_env *env);
void			p_r(t_env *env);
/*
** param_sort.c
*/
void			p_t(t_env *env);
void			p_u(t_env *env);
void			p_c(t_env *env);
void			p_f(t_env *env);
void			p_sup(t_env *env);


/*
** error.c
*/
int				err(const char *message, char *strerr, int error);
int				err_invalid_param(t_env *env, char c);
// int				err_abort(t_list *lst);

/*
** BONUS.c----------------------------------------------------------------------
*/
int				sort_by_size(t_node *nd1, t_node *nd2);
int				sort_by_ctime(t_node *nd1, t_node *nd2);
int				sort_by_atime(t_node *nd1, t_node *nd2);
int				sort_by_size_r(t_node *nd1, t_node *nd2);
int				sort_by_ctime_r(t_node *nd1, t_node *nd2);
int				sort_by_atime_r(t_node *nd1, t_node *nd2);


/*
** debug.c
*/
void			print_dir(t_env env);
void			print_env(t_env env);
void			print_path(t_env env);
void			lstput(t_list *lst, const char *name);


#endif
