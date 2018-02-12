#include "ft_wuni.h"

void	ft_putnofwstr_fd(const wchar_t *wstr, size_t n, int fd)
{
	size_t	i;
	size_t	size;

	i = 0;
	if ((size = ft_wstrlen(wstr)) < n)
		n = size;
	while(wstr[i] && i < n)
	{
		ft_putwchar_fd(wstr[i], fd);
		i++;
	}
}
