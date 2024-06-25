/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:39:18 by gvigano           #+#    #+#             */
/*   Updated: 2024/06/21 18:35:48 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_print_nbr(int n)
{
	char	*num;
	size_t	nlen;

	nlen = 0;
	num = ft_itoa(n);
	nlen = ft_print_str(num);
	free(num);
	return (nlen);
}

/*static size_t	ft_digits(long int num)
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
}*/

/*static char	*ft_itoa(int n)
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
}*/