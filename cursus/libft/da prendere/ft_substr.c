#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*dest,

	dest =(unsigned char *) malloc (len * sizeof(char));
	if (!dest)
		return (NULL);
	while (*s && len > 0)
	{
		if (s >= start)
			*dest = *s;
		s++;
		len--;
	}
	return (dest);
}