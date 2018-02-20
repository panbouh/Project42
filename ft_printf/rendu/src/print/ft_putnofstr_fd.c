#include <libft.h>

void	ft_putnofstr_fd(const char *str, size_t n, int fd)
{
	size_t	i;
	size_t	size;

	i = 0;
	if ((size = ft_strlen(str)) < n)
		n = size;
	while(str[i] && i < n)
	{
		write(fd, &str[i], 1);
		i++;
	}
}