/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:47:17 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/29 15:36:28 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	len_tot;
	size_t	src_len;
	size_t	t;

	if (!dest || !src)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len)
		len_tot = size + src_len;
	else
		len_tot = dest_len + src_len;
	t = dest_len;
	while (*src != '\0' &&  (t + 1) < size)
	{
		dest[t] = *src;
		src++;
		t++;
	}
	dest[t] = '\0';
	return (len_tot);
}

/*size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	t;
	char	*str;

	t = ft_strlen(dest);
	if (size == 0 || !dest || !src)
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
	return (t);
}*/
