void	print_env(t_env env)
{
	ft_printf("option :\nR = %i, a = %i, l = %i, r = %i, t = %i\n",
	 env.rup, env.a, env.l, env.r, env.t);
}

void	print_path(t_env env)
{
	ft_printf("----Path :-----\n");
	ft_putstab((const char**)env.path);
	ft_printf("----------------\n");
}

