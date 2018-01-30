#include "libft.h"

size_t	ft_count_udigit(unsigned long n)
{
	size_t			count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

size_t	ft_count_umaxdigit(uintmax_t n)
{
	size_t			count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}