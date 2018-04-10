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

# define	ALL_PARAM	"Ralrt"
# define	USE			"usage: ls [-Ralrt] [file ...]\0"
# define	INV_PAR		"ls: illegal option -- \0"
# define	ONE_DAY		86400
# define	SIX_MONTH	(ONE_DAY * 30) * 3 + (ONE_DAY * 31) * 3

typedef struct	s_param
{
	char	key;
	void	(*f)();
}				t_param;

typedef struct	s_error
{
	int		key;
	void	(*f)();
}				t_error;

typedef struct	s_mode
{
	char	key;
	char	*mode;
}				t_mode;

typedef struct	s_month
{
	char	*key;
	int		val;
}				t_month;

typedef struct	s_env
{
	char			l;
	char			r;
	char			rup;
	char			t;
	char			a;
	// char			*cur_path;
	char			**path;
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
t_list			*get_file(t_maxf *maxf, const char *path, int a);
int				ft_ls(char **av);

/*
** print.c
*/
int				print_info(t_list *lst, t_maxf *maxf);
void			print_list(t_env *env, t_list *lst, t_maxf *maxf);


/*
** ultils.c
*/
char			*ft_newpath(const char *path, const char *name);
int				is_pointpoint(char *dir);

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


/*
** param.c
*/
void			p_l(t_env *env);
void			p_r(t_env *env);
void			p_rup(t_env *env);
void			p_t(t_env *env);
void			p_a(t_env *env);

/*
** error.c
*/
int				err(const char *message, char *strerr, int error);
int				err_invalid_param(t_env *env, char c);

/*
** debug.c
*/
void			print_dir(t_env env);
void			print_env(t_env env);
void			print_path(t_env env);
void			lstput(t_list *lst, const char *name);


#endif
