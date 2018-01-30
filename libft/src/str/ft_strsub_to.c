char	*ft_strsub_to(const char *s, unsigned int start, char stop)
{
	char			*tronc;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(tronc = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i] && s[i] != stop)
	{
		tronc[i] = s[start];
		start++;
		i++;
	}
	tronc[i] = 0;
	return (tronc);
}
