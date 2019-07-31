#include "libft.h"
#include "onrre.h"
#include "ft_list.h"
#include "ft_printf.h"
#include "limits.h"
#include "time.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void	dellol(void **s)
{
	ft_strdel((char **)s);
}


int	main(int ac, char **av)
{
	char	tab[3][3] = {{"=\0\0"}, {"-i\0"}, {0}};
	// char	**tab;
	char	**test;
	// tab = malloc(sizeof(char *) * 3);
	// tab[0] = ft_strdup("=");
	// tab[1] = ft_strdup("-i");
	// tab[2] = 0;
	if ((test = ft_tabtskip(&av[1], (char **)tab))){
		ft_printf("res :\n");
		ft_putstab(test);
	}
	return (0);
}
