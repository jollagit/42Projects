/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:40:35 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/31 15:06:42 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *) s);
	return (NULL);
}

/*int	main(int argc, char *argv[])
{
	char	str[50];
	size_t	len;
	
	if (argc > 0)
	{
		len = ft_strlen(argv[1]);
		ft_strlcpy(str, argv[1], (len + 1));
		printf("la mia prima occorrenza: %s", ft_strchr(str, argv[2][0]));
		ft_strlcpy(str, argv[1], (len + 1));
		printf("\n l'originale: %s", strchr(str, argv[2][0]));
	}
	return (0);
}*/

/*DESCRIPTION: The strchr() function returns
a pointer to the first occurrence of the
character c in the string s.
RETURN VALUE: The  strchr()  and strrchr()
functions return a pointer to the matched
character or NULL if the character is not found.
The terminating null byte is considered part of
the string, so that if c is specified as '\0',
these functions return a pointer to the terminator.*/