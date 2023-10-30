/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:38:23 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 18:10:39 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		n--;
		ptr++;
	}
	return (s);
}

/*int	main(int argc, char *argv[])
{
	char	str[50];
	size_t	len;
	
	if (argc > 0)
	{
		len = ft_strlen(argv[1]);
		ft_memcpy(str, argv[1], (len + 1));
		ft_memset(str, argv[2][0], ft_atoi(argv[3]));
		printf("la mia stringa finale: %s \n", str);
		ft_memcpy(str, argv[1], (len + 1));
		memset(str, argv[2][0], ft_atoi(argv[3]));
		printf("la stringa originale finale: %s \n", str);
	}
	return (0);
}*/

/*DESCRIPTION: The memset() function fills the first
n bytes of the memory area pointed to by s with
the constant byte c.RETURN VALUE: The memset()
function returns a pointer to the memory area s.*/
