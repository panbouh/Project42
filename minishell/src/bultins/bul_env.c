#include "minishell.h"

void	mod_env(char *dest, char *src, char **env)
{
	(void)dest;
	(void)src;
	(void)env;
}

size_t	count_var(char **av, char **env, size_t i)	//compte le nombre de var a rajouter/modifier
{
	char	buff[BUFF_MAX];
	size_t n;

	n = 0;
	while (av[i] && ft_strchr(av[i], '='))
	{
		ft_bzero(buff, BUFF_MAX);
		ft_strncat(buff, av[i], ft_strlen_till(buff, '='));
		if (!get_venv(buff, env))
			n++;
		i++;
	}
	return (n);
}

char	**new_env(char **av, char **old, size_t i)
{
	char	buff[BUFF_MAX];
	char	**new_env;
	char	*mod;
	size_t	size;

	size = ft_tablen(old) + count_var(av, old, i);	//count du malloc
	new_env = malloc(sizeof(char *) * size + 1);
	new_env = ft_tabcpy(av, old);						//cpy lancien env si present
	while (av[i])
	{
		ft_bzero(buff, BUFF_MAX);					//flush du buffer
		ft_strncat(buff, av[i], ft_strlen_till(av[i], '='));	//rempllir buffer avec av[i] jusqua =
		if ((mod = get_venv(buff, new_env)))							//si ca exite dedans
			mod_env(mod, av[i], new_env);					//on modifie lexistant
		else
			mod_env(NULL, av[i], new_env);			//sinon on ajoute
		i++;
	}
	return (new_env);
}

int			bul_env(char **av, char **env)
{
	char	**cpy;

	if (ft_tablen(env) < 1)				//si juste env -> affiche le et casse toi
	{
		ft_putstab(env);
		return (OK);
	}
	if (!ft_strcmp(av[1], "-i"))		//si option -i, on cpy env de 0
		cpy = new_env(av, NULL, 2);		//av, on pars de 0, debut av[2] pour sauter -i
	else								//sinon on pars avec env deja la
		cpy = new_env(av, env, 1);		//av, env deja la, on pars du debut pas de -i

	return (OK);
}