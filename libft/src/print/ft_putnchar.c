#include "libft.h"

void	ft_putnchar(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
}