int	ft_isspace(char c)
{
	if (c != '\n' || c != ' ' || c != '\t')
		return (1);
	else
		return (0);
}