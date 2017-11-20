#include "laKaisse.h"

t_kaisse	take_input(t_kaisse kai)
{
	char	*input;
	size_t	i;

	i = 0;
	get_next_line(0, &input);
	while (input[i])
	{
		if (ft_strncmp("add", &input[i], 3) == 0)
			{
				i += 2;
				i = ft_skip_char(input, i, ' ', TILL);
				kai = mod_kaisse(ADD, &input[i], kai);
				return (kai);
			}
		if (ft_strncmp("del", &input[i], 3) == 0)
			{
				i += 2;
				i = ft_skip_char(input, i, ' ', TILL);
				kai = mod_kaisse(DEL, &input[i], kai);
				return (kai);
			}
		i++;
	}
	return (kai);
}

t_kaisse mod_kaisse(int flag, char *input, t_kaisse kai)
{
	size_t	i;
	int		bill;
	int		mod;

	i = 0;
	mod = ft_atoi(input);
	printf("mod = %i\n", flag);
	i = ft_skip_char(input, i, ' ', TILL);
	i = ft_skip_char(input, i, ' ', ALL);

	bill = ft_atoi(&input[i]);
	if (bill == 500)
		bill = BILL_500;
	else if (bill == 200)
		bill = BILL_200;
	else if (bill == 100)
		bill = BILL_100;
	else if (bill == 50)
		bill = BILL_50;
	else if (bill == 20)
		bill = BILL_20;
	else if (bill == 10)
		bill = BILL_10;
	else
	{
		ft_putendl("Bad expression");
		return (kai);
	}


	if (flag == ADD)
	{
		kai.bills.bill[bill] += mod;
		printf("Add %i bill of %i\n", mod, kai.bills.bill_val[bill]);
		
	}
	if (flag == DEL)
	{kai.bills.bill[bill] -= mod;
		printf("Delete %i bill of %i\n", mod, kai.bills.bill_val[bill]);
		
	}
	kai = calc_kaisse(kai);
	return (kai);
}

void	laKaisse()
{
	t_kaisse	kaisse;
	//char		*input = NULL;

	kaisse = init_kaisse();
	while (42)
	{
		print_kaisse(kaisse);
		kaisse = take_input(kaisse);
	}
}