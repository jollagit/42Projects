/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:23:23 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/31 15:36:00 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
/*int	main(int argc, char *argv[])
{
	unsigned char	*str;
	
	if (argc > 0)
	{
		str = (unsigned char *)argv[1];
		printf("mia: %p", ft_memchr(str, argv[2][0], (size_t)ft_atoi(argv[3])));
		printf("\n originale: %p", memchr(str, argv[2][0], (size_t)ft_atoi(argv[3])));
	}
	return (0);
}*/

/*DESCRIPTION: The  memchr()  function scans the initial n
bytes of the memory area pointed to by s for the first
instance of c. Both c and the bytes of the memory area 
pointed to by s are in‐terpreted as unsigned char.
RETURN VALUE: The memchr() and memrchr() functions return
a pointer to the matching byte or NULL if the character
does not occur in the given memory area.*/