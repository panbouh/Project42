#include "libft.h"
#include "limits.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	long long	nb = LLONG_MIN;
	unsigned long long unb = ULLONG_MAX;
	int		n = INT_MIN;
	// printf("Real :\n%i\nMine :\n", n);
	printf("Real :\n%lli\nMine :\n", nb);
	ft_putlnbr_fd(nb, 1);
	printf("\n----------------\nReal :\n%llu\nMine :\n", unb);
	ft_putunbr_fd(unb, 1);
	printf("\n----------------\nReal :\n%i\nMine :\n", n);
	ft_putnbr_fd(n, 1);
	return (1);
}