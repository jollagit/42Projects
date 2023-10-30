/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:06:05 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 14:11:10 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'a' && i <= 'z')
		|| (i >= 'A' && i <= 'Z'))
		return (8);
	return (0);
}
/*int	main (int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("la mia: %d \n", ft_isalnum(argv[1][0]));
	printf("quella originale: %d", isalnum(argv[1][0]));
	return (0);
}*/

/*isalnum()checks for an alphanumeric character
RETURN VALUE: The values returned are nonzero
if the character c falls into the tested class,
and zero if not.*/
