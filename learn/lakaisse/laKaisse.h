#ifndef LA_KAISSE_H
# define LA_KAISSE_H

# include "../../get_next_line/git/get_next_line.h"

# define MAX_BILL	5

# define BILL_500	5
# define BILL_200	4
# define BILL_100	3
# define BILL_50	2
# define BILL_20	1
# define BILL_10	0

# define ADD		1
# define DEL		-1

typedef struct		s_bills
{
	int bill[MAX_BILL + 1];
	int bill_val[MAX_BILL + 1];
	int bill_tot[MAX_BILL + 1];
}					t_bills;

typedef struct		s_kaisse
{
	int				total;
	t_bills			bills;
}					t_kaisse;

void	laKaisse();
void	print_kaisse(t_kaisse kai);

t_kaisse	mod_kaisse(int flag, char *input, t_kaisse kai);
t_kaisse	take_input(t_kaisse kai);
t_kaisse	init_kaisse();
t_kaisse	calc_kaisse(t_kaisse);


#endif

// 500
// 200
// 50
// 20
// 10