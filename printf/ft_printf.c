/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:07:02 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/16 15:05:44 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_print(const char *str, ...) // ... permette alla funzione di ricevere un numero qualsiasi di argomenti
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
			while (*str != '%')
				i += ft_print_char(*str);
		str++;
	}
	va_end(ptr);
	return (i);
}