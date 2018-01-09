#include "libft.h"

void	ft_putlnbr_fd(long long nb, int fd)
{
	unsigned long long n;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putlnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}