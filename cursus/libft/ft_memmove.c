/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:36:06 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 17:59:09 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*temp;
	unsigned char		*ptr;
	size_t				i;

	i = 0;
	if (dest != NULL && src != NULL)
	{
		temp = (const unsigned char *)src;
		ptr = (unsigned char *)dest;
		if (ptr > temp)
		{
			while (n-- > 0)
				ptr[n] = temp[n];
		}
		else
		{
			while (i < n)
			{
				ptr[i] = temp[i];
				i++;
			}
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
		ft_memmove(str, argv[2], ft_atoi(argv[3]));
		printf("mia: %s", str);
		ft_memcpy(ptr, argv[1], (len + 1));
		ft_memmove(ptr, argv[2], ft_atoi(argv[3]));
		printf("\n originale: %s", ptr);
	}
	return (0);
}*/

/*DESCRIPTION: The  memmove()  function  copies  n bytes
from memory area src to memory area dest.The memory areas
may overlap: copying takes place as though the bytes in
src are first copied into a temporary array that does not
overlap src or dest, and the bytes are then copied
from the temporary array to dest.
RETURN VALUE: The memmove() function returns a pointer to dest.*/
