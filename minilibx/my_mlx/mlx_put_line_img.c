#include "my_mlx.h"
#include "../mlx.h"

static void line_basex(t_mlx_env env, t_line line, int color)
{
	int add;

	if ((line.p2.x - line.p1.x) > 0 || (line.p2.y - line.p1.y) > 0)
		add = 1;
	else
		add = -1;
	while (line.p1.x != line.p2.x)
	{
		mlx_pix_put_img(env.img_str, env.s_l, line.p1, color);
		line.p1.x += add;
	}
}

static void line_basey(t_mlx_env env, t_line line, int color)
{
	int add;

	if ((line.p2.x - line.p1.x) > 0 || (line.p2.y - line.p1.y) > 0)
		add = 1;
	else
		add = -1;
	while (line.p1.y != line.p2.y)
	{
		mlx_pix_put_img(env.img_str, env.s_l, line.p1, color);
		line.p1.y += add;
	}
}

static void	line_br(t_mlx_env env, t_line line, int color)
{
	int	e;

	e = line.dx;
	line.dx = e * 2;
	line.dy = line.dy * 2;
	while (line.p1.x != line.p2.x)
	{
		mlx_pix_put_img(env.img_str, env.s_l, line.p1, color);
		line.p1.x += line.addx;
		if ((e -= line.dy) <= 0)
		{
			line.p1.y += line.addy;
			e += line.dx;
		}
	}
}

static void	line_hr(t_mlx_env env, t_line line, int color)
{
	int	e;

	e = line.dy;
	line.dy = e * 2;
	line.dx = line.dx * 2;
	while (line.p1.x != line.p2.x)
	{
		mlx_pix_put_img(env.img_str, env.s_l, line.p1, color);
		line.p1.y += line.addy;
		if ((e -= line.dx) <= 0)
		{
			line.p1.x += line.addx;
			e += line.dy;
		}
	}
}

void	mlx_put_line_img(t_mlx_env env, t_pos p1, t_pos p2, int color)
{
	t_line	line;

	line = mlx_init_line(&p1, &p2);
	if (p1.y == p2.y)
		line_basex(env, line, color);
	else if (p1.x == p2.x)
		line_basey(env, line, color);
	else if (line.dy < line.dx)
		line_br(env, line, color);
	else
		line_hr(env, line, color);
}
