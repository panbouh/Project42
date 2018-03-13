#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdlib.h> //pour exit

int	keyboard_input(int key, t_mlx_env *env)
{
	printf("key = %i\n", key);
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_SPACE)
	{
		mlx_clear_window(env->mlx_p, env->win_p);
		if (env->img_p)
			ft_bzero(env->img_str, env->s_l * WIN_Y);
	}
	return (0);
}

int	mouse_input(int but, int x, int y, t_mlx_env *env)
{
	static t_pos	p1;
	static t_pos	p2;

	printf("-------------------------------------\nbut = %i\n", but);
	printf("x = %i, y = %i\n", x, y);
	if (but == 1)
	{
		p1.x = x;
		p1.y = y;
		mlx_pix_put_img(env->img_str, env->s_l, p1, 0x00FF00);
	}
	if (but == 2)
	{
		p2.x = x;
		p2.y = y;
		mlx_put_line_img(*env, p1, p2, 0xFF0000);
	}
	mlx_put_image_to_window(env->mlx_p, env->win_p, env->img_p, 0, 0);
	return (0);
}