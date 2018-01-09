#include "libft.h"

void	ft_putunbr_fd(unsigned long long nb, int fd)
{
	if (nb >= 10)
		ft_putlnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + 48, fd);
}