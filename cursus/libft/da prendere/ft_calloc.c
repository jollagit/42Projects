#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc (count * size);
	if (count == 0 || size == 0)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}