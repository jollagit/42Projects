/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:38:06 by gvigano           #+#    #+#             */
/*   Updated: 2023/12/04 17:19:30 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

int	ft_search_format(va_list ptr, const char s)
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
		i += ft_print_percent();
	return (i);
}