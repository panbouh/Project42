#ifndef	ONRRE_H
# define ONRRE_H

# define	E_IDK		42
# define	E_IDK_STR	"i don't know why, good luck :)"

# define	E_NOPERM	-1
# define	E_NOPERM_STR	"permission denied"
# define	E_NOFOUND	-2
# define	E_NOFOUND_STR	"not found"

int	g_onrre;

typedef struct	s_onrre
{
	int		err_tag;
	char	*err_str;
}				t_onrre;

char*	get_onrre(int onrre);

int		set_onrre(int onrre, int ret);

#endif