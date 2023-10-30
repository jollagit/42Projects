/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:07:43 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 14:21:08 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("la lunghezza della stringa e': %ld", ft_strlen(argv[1]));
	}
	return (0);
}*/

/*DESCRIPTION: The strlen() function calculates the
length of the string pointed to by s, excluding
the terminating null byte ('\0').
RETURN VALUE: The strlen() function returns the
number of bytes in the string pointed to by s.*/