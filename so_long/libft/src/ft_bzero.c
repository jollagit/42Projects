/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:46:08 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 16:31:41 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i != n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*int	main(int argc, char *argv[])
{
	size_t	i;
	char	str[50];
	size_t	len;
	char 	ptr[50];
	
	if (argc > 0)
	{
		i = 0;
		len = ft_strlen(argv[1]);
		ft_memcpy(str, argv[1], (len + 1));
		ft_bzero(str, (size_t)ft_atoi(argv[2]));
		printf("la mia nuova stringa e' :");
		while (i < len)
		{
			printf("%c", str[i]);
			i++;
		}
		i = 0;
		ft_memcpy(ptr, argv[1], (len + 1));
		bzero(ptr, (size_t)ft_atoi(argv[2]));
		printf(" \n originale:");
		while (i < len)
		{
			printf("%c", ptr[i]);
			i++;
		}
	}
	return (0);
}*/

/*DESCRIPTION: The bzero() function erases the data
in the n bytes of the memory starting at the location
pointed to by s, by writing zeros
(bytes containing '\0') to that area.
RETURN VALUE: None.*/