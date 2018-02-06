#include <wchar.h>
#include "ft_wuni.h"

size_t	ft_wstrlen(const wchar_t *wstr)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!wstr)
		return (0);
	while (wstr[i])
		size += ft_wcharlen(wstr[i++]);
	return (size);
}