/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:35:25 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/28 17:57:14 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		s1++;
	len = 0;
	if (*s1 != '\0')
	{
		while (*s1++ != '\0')
			len++;
		s1 -= 2;
		while (ft_strchr(set, *s1) != NULL && s1--)
			len--;
	}
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (len != 0)
		ptr[--len] = *s1--;
	return (ptr);
}
/*int	main(int argc, char *argv[])
{
	char	*ptr;
	
	if (argc != 3)
		return (0);
	ptr = ft_strtrim(argv[1], argv[2]);
	printf("la stringa pulita e':", ptr);
	return (0);
}*/
/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string
Return value The trimmed string,
NULL if the allocation fails*/
