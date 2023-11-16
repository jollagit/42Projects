/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:39:18 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/16 14:38:39 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

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

static char	*ft_itoa(int n)
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

int	ft_print_nbr(int n)
{
	char	*num;
	size_t	nlen;

	nlen = 0;
	num = itoa(n);
	nlen = ft_print_str(num);
	free(num);
	return (nlen);
}