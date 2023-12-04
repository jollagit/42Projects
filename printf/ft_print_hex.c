/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:42:52 by gvigano           #+#    #+#             */
/*   Updated: 2023/12/04 19:06:55 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

static void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

static void	ft_put_hex(uintptr_t num, const char c)// uninptr e' un unsigend int type grande abbastanza da portare un puntatore
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, c);
		ft_put_hex(num % 16, c);
	}
	else if (num <= 9) // la funzione e' arrivta a lavorare con single digit esadecimali
		ft_putchar_fd((num + '0'), 1);
	else // la digit e' nel range tra 10 e 1 che rappresenta le gidit fra 'a' e 'f'
	{
		if (c == 'x')
			ft_putchar_fd((num - 10 + 'a'), 1);
		if (c == 'X')
			ft_putchar_fd((num - 10 + 'A'), 1);
	}
}

int	ft_print_hex(unsigned int n, const char c)
{
	size_t	i;

	i = 0;
	i += write(1, "0x", 2);
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		ft_put_hex(n, c);
		i += ft_nlen(n);
	}
	return (i);
}