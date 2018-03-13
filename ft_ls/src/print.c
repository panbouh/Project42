#include "ft_ls.h"

void	print_dir(struct dirent **dir_d)
{
	size_t	i;

	i = 0;
	while (dir_d[i])
	{
		if (dir_d[i]->d_name[0] != '.')
		{
			ft_putstr(dir_d[i]->d_name);
			ft_putchar('\n');
		}
		i++;
	}
}