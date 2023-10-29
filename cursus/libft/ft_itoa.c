/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:52:59 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/29 13:02:49 by menny            ###   ########.fr       */
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
