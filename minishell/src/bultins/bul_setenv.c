#include "minishell.h"
#include "ft_printf.h"
int		bul_setenv(char **av, t_list *env)
{
	size_t	i;
	size_t	size;
	char	*name;
	t_node	*venv;

	i = 0;
	ft_putstab(av);
	if (!av)
		return (FAIL);
	while (av[i] && ft_strchr(av[i], '='))
	{
		size = ft_strlen(av[i]);
		if ((venv = get_venv(name = ft_strsub_to(av[i], 0, '='), env)))
		{
			venv->data = av[i];
			venv->data_size = size;
		}
		else if (name[0])
			ft_lstadd_end(env, ft_lstnew_node_m(av[i], size));
		ft_strdel(&name);
		i++;
	}
	return (OK);
}