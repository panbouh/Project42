#include "libft.h"

int		ft_error(char *message, int error)
{
	ft_putendl_fd(message, 2);
	return (error);
}