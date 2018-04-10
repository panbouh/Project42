#include "ft_ls.h"

char	*ft_newpath(const char *path, const char *name)
{
	char	new[BUFF_MAX];
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	ft_bzero(new, BUFF_MAX);
	while (path[x])
	{
		new[i] = path[x];
		if (path[x] == '/')
			x = ft_skip_char(path, x, '/', ALL);
		else
			x++;
		i++;
	}
	if (new[i - 1] && new[i - 1] != '/')
		new[i++] = '/';
	ft_strcpy(&new[i], name);
	i += ft_strlen(name);
	new[i] = 0;
	return (ft_strdup(new));
}

int		is_pointpoint(char *dir)
{
	if (!ft_strcmp(dir, ".") || !ft_strcmp(dir, ".."))
		return (1);
	return (0);
}
