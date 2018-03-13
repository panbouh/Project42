#include "my_mlx.h"
#include "libft.h"

t_line	mlx_init_line(const t_pos *p1, const t_pos *p2)
{
	t_line	new;

	if (p1 && p2)
	{
		new.p1.x = p1->x;
		new.p1.y = p1->y;
		new.p2.x = p2->x;
		new.p2.y = p2->y;
		new.dx = ft_abs(p2->x - p1->x);
		new.dy = ft_abs(p2->y - p1->y);
		if ((p2->x - p1->x) > 0)
			new.addx = 1;
		else
			new.addx = -1;
		if ((p2->y - p1->y) > 0)
			new.addy = 1;
		else
			new.addy = -1;
	}
	else
		ft_bzero(&new, sizeof(new));
	return (new);
}