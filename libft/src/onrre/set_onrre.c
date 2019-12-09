#include "onrre.h"

int		set_onrre(int onrre, int ret)
{
	g_onrre = onrre;
	return (ret);
}

char	*set_onrre_c(int onrre, char *ret)
{
	g_onrre = onrre;
	return (ret);
}