void	ft_memswap(void **a, void **b)
{
	void	*save;

	save = *a;
	*a = *b;
	*b = save;
}