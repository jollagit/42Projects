/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:47:17 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/18 14:06:19 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	t;
	char	*str;

	t = ft_strlen(dest);
	if (size == 0)
		return (0);
	if (size < t)
	{
		t = 0;
		while (t < size)
		{
			dest[t] = *str;
			str++;
			t++;
		}
		return (t);
	}
	while (*src && t < size)
	{
		dest[t] = *src;
		src++;
		t++;
	}
	size = t;
	return (size);
}
