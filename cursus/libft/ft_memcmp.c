/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:52:04 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 11:19:07 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	if (!s1 || !s2 || n == 0)
		return (0);
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (n > 1)
	{
		if (*ptr_s1 != *ptr_s2)
			break ;
		ptr_s1++;
		ptr_s2++;
		n--;
	}
	return (*ptr_s1 - *ptr_s2);
}
/*int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		
		printf("mia: %d", ft_memcmp(argv[1], argv[2],
		 (size_t)ft_atoi(argv[3])));
		printf("\n originale: %d", memcmp(argv[1],
		 argv[2], (size_t)ft_atoi(argv[3])));
	}
	return (0);
}*/

/*DESCRIPTION: The memcmp() function compares the first
n bytes (each interpreted as unsigned char)
of the memory areas s1 and s2.
RETURN VALUE: The  memcmp()  function  returns  an integer
less than, equal to, or greater than zero if the first n
bytes of s1 is found, respectively, to be less than, to match,
or be greater than the first n bytes of s2.*/