/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:47:17 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/09 16:23:11 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t      ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	if (size == 0)
		return (0);
	while (dest[i] == "\0")
		i++;
	while (src[t])
	{
		dest[i] = src[t];
		i++;
		t++;
	}
	dest[i] = "\0";
	size = i;
	return (size);
}