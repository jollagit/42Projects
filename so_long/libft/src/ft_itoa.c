/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:52:59 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 11:30:00 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(long int num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		i++;
	if (num < 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	size_t		digits;
	long int	num;

	num = (long int)n;
	digits = ft_digits(num);
	ptr = (char *) malloc (sizeof (char) * (digits + 1));
	if (!ptr)
		return (NULL);
	if (num == 0)
		ptr[0] = '0';
	if (num < 0)
	{
		*ptr = '-';
		num *= -1;
	}
	*(ptr + digits) = '\0';
	while (num != 0)
	{
		digits--;
		*(ptr + digits) = num % 10 + '0';
		num /= 10;
	}
	return (ptr);
}
/*int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("il numero diventa: %s", ft_itoa(ft_atoi(argv[1])));
	return (0);
}*/

/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
Return value: The string representing the integer.
NULL if the allocation fails.*/