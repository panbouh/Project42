#include "onrre.h"
#include <stdlib.h>

t_onrre		g_errtab[] =
{
	{E_NOPERM, E_NOPERM_STR},
	{E_NOFOUND, E_NOFOUND_STR},
	{-4896, NULL},
};

char*	get_onrre(int onrre)
{
	size_t	i;

	i = 0;
	while(g_errtab[i].err_tag)
	{
		if (onrre == g_errtab[i].err_tag)
			return (g_errtab[i].err_str);
		i++;
	}
	return (E_IDK_STR);
}

int		set_onrre(int onrre, int ret)
{
	g_onrre = onrre;
	return (ret);
}