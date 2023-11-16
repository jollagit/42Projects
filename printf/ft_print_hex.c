/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:42:52 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/16 15:12:06 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

static int	ft_nlen(uintptr_t n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
static void	ft_put_hex(uintptr_t num, const char c)// uninptr e' un unsigend int type grande abbastanza da portare un puntatore
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, c);
		ft_put_hex(num % 16, c);
	}
	else if (num <= 9) // la funzione e' arrivta a lavorare con single digit hexadecimali
		ft_putchar_fd((num + '0'), 1);
	else // la digit e' nel range tra 10 e 1 che rappresenta le gidit fra 'a' e 'f'
	{
		if (c == 'x')
			ft_putchar_fd((num - 10 + 'a'), 1);
		if (c == 'X')
			ft_putchar_fd((num - 10 + 'A'), 1);
	}
}

int	ft_print_hex(unsigned int n)
{
	size_t	i;

	i = 0;
	i += write(1, "0x", 2);
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		ft_put_hex(n);
		i += ft_nlen(n);
	}
	return (i);
}