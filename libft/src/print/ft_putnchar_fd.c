#include <unistd.h>

void	ft_putnchar_fd(char c, size_t n, int fd)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		write(fd, &c, 1);
}
