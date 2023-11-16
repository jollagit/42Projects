/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:45:29 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/16 12:32:17 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

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
	char			*num;
	size_t			len;

	len = ft_nlen(n);
	num = (char *) malloc ((len + 1) * sizeof(char));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len -1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (num);
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