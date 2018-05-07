#include "ft_ls.h"

int		err(const char *message, char *strerr, int error)
{
	size_t	i;
	if (!message)
		return (error);
	ft_putstr_fd("ls: ", 2);
	if ((i = ft_strlen(message)))
	{
		while (i != 0 && message[i - 1] != '/')
			i--;
	}
	ft_putstr_fd(&message[i], 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerr, 2);
	return (error);
}

int		err_invalid_param(t_env *env, char c)
{
	ft_putstr_fd(INV_PAR, 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd(USE, 2);
	return (FAIL);
}

// int		err_abort(t_list *lst)
// {
// 	delall(lst);
// 	return (FAIL);
// }