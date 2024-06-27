/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:06:20 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 14:14:07 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}

/*int	main (void)
{
	char	c;

	c = 125;
	printf("la mia: %d \n", ft_isascii(c));
	printf("quella originale: %d", isascii(c));
	return (0);
}*/

/*isascii() checks whether c is a 7-bit unsigned
char value that fits into the ASCII character set.
RETURN VALUE: The values returned are nonzero if
the character c falls into the tested class,
and zero if not*/
