#include "fdf.h"
#include "mlx.h"
#include "libft.h"

char	*ft_strjoin_del(char *s1, char *s2, int del)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (del == 1)
		ft_strdel(&s1);
	if (del == 2)
		ft_strdel(&s2);
	if (del == ALL)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (new);
}

t_map	init_map(int fd)
{
	t_map	map;
	int		rd;
	char	*file;
	char	*line;
	char	*save;
	size_t	y;
	size_t	size;

	file = NULL;
	y = 0;
	while ((rd = get_next_line(fd, &line)) != RD_END)
	{
		size += ft_strlen(line);
		file = ft_strjoin_del(file, line, 1);
		file = ft_strjoin_del(file, "\n", 1);
		y++;
	}
	map.map = (const char **)ft_strsplit(file, '\n');
	ft_strdel(&file);
	map.y = y;
	map.size = size * y;
	return (map);
}

t_mlx_env	init_all()
{
	t_mlx_env	env;

	env.mlx_p = mlx_init();
	env.win_p = mlx_new_window(env.mlx_p, WIN_X, WIN_Y, "fdf");

	env.img_p = mlx_new_image(env.mlx_p, WIN_X, WIN_Y);
	env.img_str = mlx_get_data_addr(env.img_p,
									&env.bpp, &env.s_l, &env.endian);
	return (env);
}