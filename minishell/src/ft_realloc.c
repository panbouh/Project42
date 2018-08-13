#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void *new;

	new = ft_memalloc(size);
	new = ft_memcpy(new, src, size);
	ft_memdel(&src);
	return (new);
}