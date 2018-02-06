#include "libft.h"
#include "ft_wuni.h"
#include "limits.h"
#include <locale.h>

int	main(int ac, char **av)
{
	setlocale(LC_ALL, "");
//----------------------------------------------
	wchar_t *s = ft_wstrdup(L"❤✖ĄѺ");
	ft_putnofwstr(s, 3);
	ft_putchar('\n');
	ft_wstrdel(&s);
	return (1);
}
