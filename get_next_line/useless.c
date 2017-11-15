int		ft_tablen(const char	**tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

void	ft_ctabdel(char ***tab)
{
	size_t	i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while (*tab[i])
	{
		ft_strdel(tab[i]);
		i++;
	}
	*tab = NULL;
}



char	**ft_realloc(char **s, size_t size)
{
	char	**new;
	size_t	i;

	i = 0;
	if (size == 0)
		return (s);
	if (!(new = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	if (!s)
		return (new);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	ft_ctabdel(&s);
	while (i < size)
		new[i++] = 0;
	return (new);
}