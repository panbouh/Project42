#include "onrre.h"
#include "libft.h"

int		put_onrre(char *s, int ret)
{
	if (s)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(" : ", 2);
	}
	ft_putendl_fd(get_onrre(g_onrre), 2);
	return (ret);
}