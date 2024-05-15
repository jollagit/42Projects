/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:05:41 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 14:13:01 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1024);
	return (0);
}

/*int	main (int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("la mia: %d \n", ft_isalpha(argv[1][0]));
	printf("quella originale: %d", isalpha(argv[1][0]));
	return (0);
}*/

/* isalpha()checks for an alphabetic character;
in the standard "C" locale, it is equivalent to
(isupper(c) || islower(c)).  In some locales,
there may be additional charac‐ters for which
isalpha() is true—letters which are neither
uppercase nor lowercase.
RETURN VALUE: The values returned are nonzero
if the character c falls into the tested class,
and zero if not.*/