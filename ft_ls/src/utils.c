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

static int		lendir(struct dirent **src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

struct dirent	**dupdir(struct dirent **src)
{
	size_t	i;
	struct	dirent	**new;

	new = malloc(sizeof(struct dirent**) * lendir(src));
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

int		is_pointpoint(char *dir)
{
	if (!ft_strcmp(dir, ".") || !ft_strcmp(dir, ".."))
		return (1);
	return (0);
}
