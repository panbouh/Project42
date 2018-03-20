#include "libft.h"

void	*ft_memdup(const void *src, size_t size)
{
	void	*new;
	void	*tmp;

	tmp = new + size;
	new = ft_memalloc(size);
	new = ft_memcpy(new, src, size);
	tmp = NULL;
	return (new);
}