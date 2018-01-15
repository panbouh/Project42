#include <ft_printf.h>

void	conv_j(va_list ap, t_flag_list t_fl, char form)
{
	t_key	keytab[] =
	{
		{'i', &conv_intmaxt},			\
		{'d', &conv_intmaxt},			\
		{'u', &conv_uintmaxt},			\
		{'x', &conv_uintmaxthexa},		\
		{'X', &conv_uintmaxthexaup},	\
		{'o', &conv_uintmaxtocta},		\
		{0, NULL},
	};

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, fl)
			return ;
		}
		i++;
	}
}

void	conv_z(va_list ap, t_flag_list t_fl, char form)
{
	t_key	keytab[] =
	{
		{'i', &sizet},			\
		{'d', &sizet},			\
		{'u', &sizet},			\
		{'x', &sizethexa},		\
		{'X', &sizethexaup},	\
		{'o', &sizetocta},		\
		{0, NULL},
	};

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, fl)
			return ;
		}
		i++;
	}
}