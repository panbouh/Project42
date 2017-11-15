#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	pc(char c)
{
	write(1, &c, 1);
}

void	nbr(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		pc ('-');
	}
	if (nb > 10)
		nbr(nb / 10);
	pc((nb % 10) + 48);
}

int	fac(int nb)
{
	if (nb > 1)
		nb *= fac(nb - 1);
	return (nb);
}

int rpow(int nb, int pow)
{
	int save;

	save = nb;
	if (pow > 1)
		nb *= rpow(nb, pow - 1);
	return (nb);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("les arg enculer\n");
		return (-1);
	}

	//nbr(atoi(av[1]));
	//printf("ret fac = %i", fac(atoi(av[1])));
	printf("ret rpow = %i", rpow(atoi(av[1]), atoi(av[2])));
	return (0);
}