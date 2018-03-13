#include "my_mlx.h"
#include <limits.h>

void	mlx_pix_put_img(char *img_str, int size, t_pos p, unsigned int color)
{
	int	*img;
	int	i;

	i = 0;
	i += p.x + p.y * (size / 4);
	img = (int *)img_str;

	img[i] = color;
}
