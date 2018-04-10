#include "ft_ls.h"

// t_error	g_errtab[] =
// {
// 	{INV_PAR, &err_invalid_param},
// 	{0, NULL},
// };

int		err(const char *message, char *strerr, int error)
{
	size_t	i;
	if (!message)
		return (error);
	i = ft_strlen(message);
	ft_putstr_fd("ls: ", 2);
	while (message[i - 1] && message[i - 1] != '/')
		i--;
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

// int		err_abort(t_env *env, int err)
// {
// 	size_t	i;

// 	i = 0;
// 	while(g_errtab[i].key)
// 	{
// 		if (err == g_errtab[i].key)
// 			g_errtab[i].f(t_env *env);
// 		i++;
// 	}
// 	return (FAIL);
// }