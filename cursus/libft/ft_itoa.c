/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:52:59 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/28 19:41:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	size_t		digits;

	if (n < -2147483647)
	{
		ptr = (char *) malloc (sizeof(char) * 12);
		ptr = "-2147483648";
		return (ptr);
	}
	digits = ft_digits(n);
	ptr = (char *) malloc (sizeof (char) * (digits + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		*ptr = '-';
		n *= -1;
	}
	*(ptr + digits) = '\0';
	while (n != 0)
	{
		digits--;
		*(ptr + digits) = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
