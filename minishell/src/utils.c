#include <unistd.h>

#include "minishell.h"

char	*get_pwd()
{
	char	*buff;
	size_t	i;

	buff = ft_strnew(BUFF_MAX);
	i = 0;
	while (!getcwd(buff, BUFF_MAX + i))
	{
		i += sizeof(char) * 42;
		ft_realloc(buff, i);
	}
	return (buff);
}

char	*get_venv(char *v_name, char **env)
{
	size_t	i;
	size_t	size;

	if (!v_name || !env)
		return (NULL);
	size = ft_strlen(v_name);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(v_name, env[i], size))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*get_venv_val(char *v_name, char **env)
{
	char	*venv;

	if (!(venv = get_venv(v_name, env)))
		return (NULL);
	if (!(venv = ft_strchr(venv, '=') + 1))
		return (NULL);
	return (venv);
}