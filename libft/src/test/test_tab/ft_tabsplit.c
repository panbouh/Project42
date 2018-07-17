#include "libft.h"

int		**ft_tabsplit(const char *str)
{
	int		**tab;
	char	*line;
	size_t	size_l;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;

	tab = malloc(sizeof(int *) * ft_strlen_c(str, '\n'));
	while (str[i])
	{
		size_l = ft_strlen_till(str, '\n');
		line = ft_strsub(str, i, size_l);
		tab[y] = ft_strtotab(line, NULL);
		ft_strdel(&line);
		y++;
		i += size_l;
	}
	return (tab);
}