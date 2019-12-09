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
	g_onrre = E_NOPERM;

	put_onrre("coucou", 0);
	return (0);
}
