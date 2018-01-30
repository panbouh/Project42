#include <limits.h>
#include "libft.h"

unsigned long long ft_abs_ll(long long n)
{
	unsigned long long	res;
	
	if (n < 0)
	{
		res = -n;
		return (res);
	}
	return ((unsigned long long)n);
}

unsigned long ft_abs_l(long n)
{
	unsigned long	res;
	
	if (n < 0)
	{
		res = -n;
		return (res);
	}
	return ((unsigned long)n);
}

unsigned int ft_abs(int n)
{
	unsigned int	res;

	if (n < 0)
	{
		res = -n;
		return (res);
	}
	return ((unsigned int)n);
}