/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:29:57 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/31 18:18:25 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*ptr;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	ptr = (char *) malloc ((i + 1) * sizeof(char));
	if (!ptr)
		return (ptr);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int	main (int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("la stringa duplicata: %s", ft_strdup(argv[1]));
}*/

/*The  strdup() function returns a pointer to a new
 string which is a duplicate of the string s.
 Memory for the new string is obtained with malloc(3),
 and can be freed with free.*/