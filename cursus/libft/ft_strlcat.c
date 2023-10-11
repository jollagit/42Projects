/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:47:17 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/11 17:14:56 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	t;

	t = 0;
	if (size == 0)
		return (0);
	while (dest[t] != '\0')
		t++;
	while (*src)
	{
		dest[t] = *src;
		src++;
		t++;
	}
	size = t;
	return (size);
}
