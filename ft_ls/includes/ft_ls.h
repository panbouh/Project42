#ifndef FT_LS_H
# define FT_LS_H

#include "libft.h"
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

typedef struct	s_type
{
	unsigned char	key;
	char			type;
}				t_type;

typedef struct	s_right
{
	char	key;
	char			*right;
}				t_right;

typedef struct	s_env
{
	char			l;
	char			r;
	char			rup;
	char			t;
	char			a;
	char			**path;
	struct dirent	**dir_d;
}				t_env;

typedef struct	s_finfo
{
	char			type;
	char			*mode;
	struct stat		file_s;
	struct passwd	*file_p;
	struct group	*group_p;
	char			**time;
	size_t			max_gr;
	size_t			max_uname;
	size_t			max_name;
	size_t			max_link;
	size_t			max_byte;
}				t_finfo;

/*
** ft_ls.c
*/
int				get_file(t_env *env, const char *path);
int				list_file(t_env *env, const char *path);
int				ft_ls(char **av);

/*
** print.c
*/
int				print_info(struct dirent *dir_d, t_finfo f_info,
							const char *path);
void			print_list(t_env env, struct dirent **dir_d, const char *path);

/*
** ultils.c
*/
char			*ft_newpath(const char *path, const char *name);
int				is_pointpoint(char *dir);
struct dirent	**dupdir(struct dirent **src);

/*
** get.c
*/
char			**get_time(struct stat file_s);
int				get_max_info(struct dirent *dir_d, t_finfo *f_info);
char			*get_fmode(unsigned int n);
char			get_ftype(unsigned char c);

/*
** init.c
*/
size_t			init_file(struct dirent **dir_d, t_finfo *f_info,
								const char *path);
int				check_param(t_env *env, char **av, size_t *y);
int				init_env(t_env *env, char **av);

/*
** sorting.c
*/
void			sort_file(t_env *env);
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
int				err_invalid_param(t_env *env, char c);

/*
** debug.c
*/
void			print_dir(t_env env);
void			print_env(t_env env);
void			print_path(t_env env);


#endif
