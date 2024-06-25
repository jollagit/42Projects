/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:18:12 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 18:59:43 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size -1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*int	main(int argc, char *argv[])
{
	char	str[50];
	size_t	len;
	
	if (argc > 0)
	{
		len = ft_strlen(argv[1]);
		ft_strlcpy(str, argv[1], (len + 1));
		ft_strlcpy(str, argv[2], ft_atoi(argv[3]));
		printf("la mia stringa finale: %s \n", str);
	}
	return (0);
}*/

/*DESCRIPTION: The strlcpy() function copies up to
size - 1 characters from the NUL-terminated string
src to dst, NUL-terminating the result.
RETURN VALUES: The strlcpy() return the total length
of the string they tried to create.
For strlcpy() that means the length of src.*/