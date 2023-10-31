/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:09 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/31 15:06:30 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0 && s[i] != ((char)c))
		i--;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
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
		printf("la mia occorrenza: %s", ft_strrchr(str, argv[2][0]));
		ft_strlcpy(str, argv[1], (len + 1));
		printf("\n l'originale: %s", strrchr(str, argv[2][0]));
	}
	return (0);
}*/

/*DESCRIPTION: The strrchr() function returns a
pointer to the last occurrence of the character
c in the string s.
RETURN VALUE: The  strchr()  and strrchr() functions
return a pointer to the matched character or NULL if
the character is not found.The terminating null byte
is considered part ofthe string, so that if c is
specified as '\0', these functions return a pointer
to the terminator.*/