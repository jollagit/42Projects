/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:07:02 by gvigano           #+#    #+#             */
/*   Updated: 2023/12/04 19:44:19 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		i += ft_print_ptr(va_arg(ptr, unsigned long long));
	else if (s == 'd' || s == 'i')
		i += ft_print_nbr(va_arg(ptr, int));
	else if (s == 'u')
		i += ft_print_unbr(va_arg(ptr, unsigned int));
	else if (s == 'x' || s == 'X')
		i += ft_print_hex(va_arg(ptr, unsigned int), s);
	else if (s == '%')
		i += write(1, '%', 1);
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

/* ... permette alla funzione diricevere un elenco
variabile di argomenti facoltativi.
va_list	ptr: puntatore all'elenco variabile di argomenti facoltativi */
