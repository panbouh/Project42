#include "laKaisse.h"


t_kaisse init_kaisse()
{
	t_kaisse	kai;
	size_t		i;

	i = 0;
	while (i <= MAX_BILL)
		{
			kai.bills.bill[i] = 0;
			kai.bills.bill_tot[i] = 0;
			i++;
		}
	kai.bills.bill_val[BILL_500] = 500;
	kai.bills.bill_val[BILL_200] = 200;
	kai.bills.bill_val[BILL_100] = 100;
	kai.bills.bill_val[BILL_50] = 50;
	kai.bills.bill_val[BILL_20] = 20;
	kai.bills.bill_val[BILL_10] = 10;
	kai.total = 0;
	return (kai);
}

t_kaisse	calc_kaisse(t_kaisse kai)
{
		size_t		i;

	i = 0;
	while (i <= MAX_BILL)
		{
			kai.bills.bill_tot[i] = kai.bills.bill[i] * kai.bills.bill_val[i];
			kai.total += kai.bills.bill_tot[i];
			i++;
		}
	return (kai);
}