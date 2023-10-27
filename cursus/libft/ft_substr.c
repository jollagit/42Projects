/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:16:56 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/27 16:46:51 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > (len_s - start))
		len = len_s - start;
	dest = (char *) malloc ((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
/*int	main (int argc, char *argv[])
{
	char	*str;
	
	if (argc != 4)
		return (0);
	str = ft_substr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	printf("il risultato e': %s", str);
	return (0);
}*/

/*Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
Return value: The substring,
NULL if the allocation fails.*/