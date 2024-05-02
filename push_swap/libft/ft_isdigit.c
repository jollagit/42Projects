/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:06:31 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/02 16:22:49 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if ((i >= '0' && i <= '9') || i == ' ')
		return (2048);
	return (0);
}

/*int	main (int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("la mia: %d \n", ft_isdigit(argv[1][0]));
	printf("quella originale: %d", isdigit(argv[1][0]));
	return (0);
}*/

/*isdigit()checks for a digit (0 through 9).
RETURN VALUE: The values returned are nonzero
if the character c falls into the tested class,
and zero if not.*/