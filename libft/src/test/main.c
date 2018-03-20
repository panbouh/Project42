#include "libft.h"
#include "ft_printf.h"
#include "limits.h"
#include "time.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

int	main(int ac, char **av)
{

	ft_printf("%.*s\n", 2, "bouh");
	return (1);
}
