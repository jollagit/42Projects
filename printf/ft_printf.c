/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:07:02 by gvigano           #+#    #+#             */
/*   Updated: 2023/12/04 19:29:59 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
