/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:07:02 by gvigano           #+#    #+#             */
/*   Updated: 2024/01/29 14:22:50 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_search_format(va_list ptr, const char s)
{
	size_t	i;

	i = 0;
	if (s == 'c')
		i += ft_print_char(va_arg(ptr, int));
	else if (s == 's')
		i += ft_print_str(va_arg(ptr, char *));
	else if (s == 'p')
		i += ft_print_ptr(va_arg(ptr, void *));
	else if (s == 'd' || s == 'i')
		i += ft_print_nbr(va_arg(ptr, int));
	else if (s == 'u')
		i += ft_print_unbr(va_arg(ptr, unsigned int));
	else if (s == 'x' || s == 'X')
		i += ft_print_hex(va_arg(ptr, unsigned int), s);
	else if (s == '%')
		i += write(1, &s, 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	i;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_search_format(ptr, *(str + 1));
			str++;
		}
		else
			i += ft_print_char(*str);
		str++;
	}
	va_end(ptr);
	return (i);
}

/*int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	ft_printf("char stampati  %d \n", ft_printf(" %p %p ", argv[1], argv[2]));
	ft_printf("char stampati  %d \n", printf(" %p %p ", argv[1], argv[2]));
	return (0);
}*/

/* ... permette alla funzione di ricevere un elenco
variabile di argomenti facoltativi.
va_list	ptr: puntatore all'elenco variabile di argomenti facoltativi */
