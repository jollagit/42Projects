/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:40:32 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/16 13:02:29 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

static int	ft_ptr_len(uintptr_t n)
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

static void	ft_put_ptr(uintptr_t num)// uninptr e' un unsigend int type grande abbastanza da portare un puntatore
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else if (num <= 9) // la funzione e' arrivta a lavorare con single digit hexadecimali
		ft_putchar_fd((num + '0'), 1);
	else // la digit e' nel range tra 10 e 1 che rappresenta le gidit fra 'a' e 'f'
		ft_putchar_fd((num - 10 + 'a'), 1);
}

int	ft_print_ptr(const void *ptr)
{
	size_t	i;

	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		i += ft_ptr_len(ptr);
	}
	return (i);
}