#include <unistd.h>

void ft_putchar(char c);
void sastantua(int size);

int	main(int ac, char **av)
{
	sastantua(atoi(av[1]));
	return (0);
}
