#include "libft.h"
#include "ft_wuni.h"
#include "limits.h"
#include <locale.h>

int	main(int ac, char **av)
{
	setlocale(LC_ALL, "");
//----------------------------------------------
	wchar_t *s = ft_wstrdup(L"❤✖ĄѺ");
	char	c = 0;
	wchar_t	wc = 0;
	printf("%05c", 'a');
	ft_putstr("<\t");

	ft_putwchar(wc);

	ft_putstr("\t>\n");

	// printf("s[0] = %C\n", s[0]);

	ft_wstrdel(&s);
	return (1);
}