/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:18:34 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/27 16:21:11 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	t;

	if (!big)
		return (NULL);
	if (*lit == '\0')
		return ((char *) big);
	while (*big != '\0' && len != 0)
	{
		t = 0;
		while (lit[t] != '\0' && *(big + t) == lit[t] && (len - t) > 0)
			t++;
		if (lit[t] == '\0')
			return ((char *) big);
		len--;
		big++;
	}
	return (NULL);
}
/*int	main (int argc, char *argv[])
{
	char	*result;
	
	if (argv != 4)
		return (0);
	result = ft_strnstr(argv[1], argv[2], argv[3]);
	if (result != NULL)
		printf("il risultato della ricerca e' un successo");	
	else	
	printf("il risultato della ricerca e' un fallimento");
	return (0);
}*/	

/*The strnstr() function locates the first occurrence of the null-terminated 
string little in the string big, where not more than len characters are searched.
Characters that appear after a ‘\0’ character are not searched.
RETURN VALUES
If little is an empty string, big is returned; if little occurs nowhere in big,
NULL is returned; otherwise a pointer to the first character of the first 
occurrence of little is returned.*/