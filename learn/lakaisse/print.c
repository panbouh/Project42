#include "laKaisse.h"

void print_kaisse(t_kaisse kai)
{
	size_t		i;

	i = 0;
	ft_putendl("/--KAISSE--\\");
	ft_putendl("Billet :\t10\t20\t50\t100\t200\t500");
	ft_putnchar('-', 60);
	ft_putstr("\nNombre :\t");
	while (i <= MAX_BILL)
	{
		ft_putnbr(kai.bills.bill[i]);
		ft_putstr("\t");
		i++;
	}
	ft_putchar('\n');
	ft_putnchar('-', 60);
	ft_putstr("\nTotal  :\t");
	i = 0;
	while (i <= MAX_BILL)
	{
		ft_putnbr(kai.bills.bill_tot[i]);
		ft_putstr("\t");
		i++;
	}
	ft_putchar('\n');
	ft_putnchar('-', 25);
	ft_putstr("TOTAL : ");
	ft_putnbr(kai.total);
	ft_putnchar('-', 25);

	ft_putstr("\n\n");
}