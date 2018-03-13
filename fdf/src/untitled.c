	tool.img_p = mlx_new_image(tool.mlx_p, WIN_X, WIN_Y);
	tool.img_str = mlx_get_data_addr(tool.img_p,
									&tool.bpp, &tool.s_l, &tool.endian);

	tool.img_str[8] = 127;
	tool.img_str[9] = 127;
	tool.img_str[10] = 127;
	tool.img_str[11] = 0;

	mlx_put_image_to_window(tool.mlx_p, tool.win_p, tool.img_p, 0, 0);




	static t_pos	p1;
	static t_pos	p2;

	printf("-------------------------------------\nbut = %i\n", but);
	printf("x = %i, y = %i\n", x, y);
	if (but == 1)
	{
		mlx_pixel_put(env->mlx_p, env->win_p, x, y, 0x00FF00);
		p1.x = x;
		p1.y = y;
	}
	if (but == 2)
	{
		p2.x = x;
		p2.y = y;
		mlx_put_line(*env, p1, p2, 0xFF0000);
	}
	// mlx_put_image_to_window(env->mlx_p, env->win_p, env->img_p, 0, 0);
	return (0);