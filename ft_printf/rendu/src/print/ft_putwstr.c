#include "libft.h"
#include "ft_wuni.h"

void	ft_putwstr(const wchar_t *wstr)
{
	size_t	i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}