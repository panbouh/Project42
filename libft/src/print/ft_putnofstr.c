#include <unistd.h>
#include <libft.h>

void	ft_putnofstr(const char *str, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	if ((size = ft_strlen(str)) < n)
		n = size;
	while(str[i] && i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
}