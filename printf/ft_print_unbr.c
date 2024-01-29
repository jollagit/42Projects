/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:45:29 by gvigano           #+#    #+#             */
/*   Updated: 2024/01/29 13:02:11 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	len = ft_nlen(n);
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	*(ptr + len) = '\0';
	while (n != 0)
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
