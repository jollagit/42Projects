/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:05:20 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 14:15:59 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i < 127)
		return (16384);
	return (0);
}

/*int	main (void)
{
	char	c;

	c = 128;
	printf("la mia: %d \n", ft_isprint(c));
	printf("quella originale: %d", isprint(c));
	return (0);
}*/

/*isprint()checks for any printable character
including space.RETURN VALUE: The values returned
are nonzero if the character c falls into the tested
class, and zero if not.*/