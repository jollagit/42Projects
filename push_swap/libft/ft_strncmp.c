/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:56:07 by gvigano           #+#    #+#             */
/*   Updated: 2024/04/19 19:36:36 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || n == 0)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && n > 1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
/*int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("il mio risultato: %d",
		ft_strncmp(argv[1], argv[2], ft_atoi(argv[3])));
		printf("\n l'originale: %d",
		strncmp(argv[1], argv[2], ft_atoi(argv[3])));
	}
	return (0);
}*/

/*DESCRIPTION: The  strcmp() function compares the two strings s1 and s2. 
It returns an integer less than, equal to, or greater than zero if s1
is found, respectively, to be less than, to match,
or be greater than s2.
The strncmp() function is similar, except it compares only
the first (at most) n bytes of s1 and s2.
RETURN VALUE: The strcmp() and strncmp() functions return an
integer less than, equal to, or greater than zero if s1
(or the first n bytes thereof) is found, respectively, to be less
than, to match, or be greater than s2.*/