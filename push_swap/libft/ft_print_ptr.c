/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:40:32 by gvigano           #+#    #+#             */
/*   Updated: 2024/04/19 18:24:54 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*static void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}*/

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else if (num <= 9)
		ft_putchar_fd((num + '0'), 1);
	else
		ft_putchar_fd((num - 10 + 'a'), 1);
}

int	ft_print_ptr(void *p)
{
	size_t		i;
	uintptr_t	ptr;

	i = 0;
	ptr = (uintptr_t)p;
	if (ptr == 0)
		i += write(1, "(nil)", 5);
	else
	{
		i += write (1, "0x", 2);
		ft_put_ptr(ptr);
		i += ft_ptr_len(ptr);
	}
	return (i);
}

/* uninptr e' un unsigend int type grande
abbastanza da portare un puntatore.
   
   if (num <= 9): la funzione e' arrivta a 
   lavorare con single digit esadecimali.

else:la digit e' nel range tra 10 e 15 che
rappresenta le digit fra 'a' e 'f'. */