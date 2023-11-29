
# include "get_next_line.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	i;

	if (!s1 || !s2)
		return ("");
	ptr = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ptr[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ptr[i++] = *s2;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}