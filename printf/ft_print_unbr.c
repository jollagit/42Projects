/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:45:29 by gvigano           #+#    #+#             */
/*   Updated: 2023/12/04 19:24:38 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_nlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	char			*ptr;
	size_t			len;
	long int		num;

	num = (long int)n;
	len = ft_nlen(num);
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	*(ptr + len) = '\0';
	while (num != 0)
	{
		len--;
		*(ptr + len) = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}

int	ft_print_unbr(unsigned int n)
{
	char	*num;
	size_t	i;

	i = 0;
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(n);
		i += ft_print_str(num);
		free(num);
	}
	return (i);
}
