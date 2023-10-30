/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:25:44 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 18:01:04 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr_s;
	size_t				i;

	i = 0;
	if (dest != NULL && src != NULL)
	{
		ptr = (unsigned char *)dest;
		ptr_s = (const unsigned char *)src;
		while (i < n)
		{
			ptr[i] = ptr_s[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(int argc, char *argv[])
{
	char	str[50];
	size_t	len;
	char 	ptr[50];
	
	if (argc > 0)
	{
		len = ft_strlen(argv[1]);
		ft_memcpy(str, argv[1], (len + 1));
		ft_memcpy(str, argv[2], ft_atoi(argv[3]));
		printf("mia: %s", str);
		ft_memcpy(ptr, argv[1], (len + 1));
		ft_memcpy(ptr, argv[2], ft_atoi(argv[3]));
		printf("\n originale: %s", ptr);
	}
	return (0);
}*/

/*DESCRIPTION: The memcpy() function copies n bytes
from memory area src to memory area dest.
The memory areas must not overlap.
RETURN VALUE: The memcpy() function
returns a pointer to dest.*/
