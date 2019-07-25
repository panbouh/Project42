#include "minishell.h"

void	mod_env(char *dest, char *src, char **env)
{
	size_t	size;

	if (dest)
	{
		size = ft_strlen(src);
		dest = ft_realloc( dest, (size + 1) * sizeof(char));
		while (src[size])
		{
			dest[size] = src[size];
			size++;
		}
	}
	else
	{
		size = ft_tablen(env);
		env[size] = ft_strdup(src);
	}
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

char	**new_env(char **av, char **old, size_t *i)
{
	char	buff[BUFF_MAX];
	char	**new_env;
	char	*mod;
	size_t	size;

	size = ft_tablen(old) + count_var(av, old, *i);	//count du malloc
	new_env = malloc(sizeof(char *) * size + 1);
	new_env = ft_tabcpy(new_env, old);				//cpy lancien env si present
		ft_putstr("new_env :\n");
	ft_putstab(new_env);
	while (av[*i] && ft_strchr(av[*i], '='))
	{
		ft_printf("av[i] = %s\n", av[*i]);
		ft_bzero(buff, BUFF_MAX);					//flush du buffer
		ft_strncat(buff, av[*i], ft_strlen_till(av[*i], '='));	//rempllir buffer avec av[i] jusqua =
		if ((mod = get_venv(buff, new_env)))							//si ca exite dedans
			mod_env(mod, av[*i], new_env);					//on modifie lexistant
		else
			mod_env(NULL, av[*i], new_env);			//sinon on ajoute
		(*i)++;
	}
	ft_putstr("new_env :\n");
	ft_putstab(new_env);
	return (new_env);
}

int			bul_env(char **av, char **env)
{
	char	**cpy;
	size_t		i;

	i = 0;
	if (ft_tablen(av) == 1)				//si juste env -> affiche le et casse toi
	{
		ft_putstab(env);
		return (OK);
	}
	if (!ft_strcmp(av[1], "-i"))			//si option -i, on cpy env de 0
	{
		i = 2;
		cpy = new_env(av, NULL, &i);		//av, on pars de 0, debut av[2] pour sauter -i
	}
	else//sinon on pars avec env deja la
	{
		i = 1;
		cpy = new_env(av, env, &i);		//av, env deja la, on pars du debut pas de -i
	}
	ft_printf("end &av[i] = %s\nenv :\n", &av[i]);
	ft_putstab(cpy);
	a_out(&av[i], cpy);
	return (OK);
}