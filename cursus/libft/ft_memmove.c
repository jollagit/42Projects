/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:36:06 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/18 17:03:20 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*ptr;
	size_t			i;

	temp = (unsigned char *)src;
	ptr = (unsigned char *)dest;
	if (ptr > temp)
		ptr[n] = temp[n];
	while (i < n)
	{
		ptr[i] = temp[i];
		i++;
	}
	return (dest);
}
