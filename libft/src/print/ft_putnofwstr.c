#include "ft_wuni.h"

void	ft_putnofwstr(const wchar_t *wstr, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	if ((size = ft_wstrlen(wstr)) < n)
		n = size;
	while(wstr[i] && i < n)
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}
