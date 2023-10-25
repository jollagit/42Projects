/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:36:06 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/25 15:52:04 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*temp;
	unsigned char		*ptr;
	size_t				i;

	i = 0;
	if (dest != NULL && src != NULL)
	{
		temp = (const unsigned char *)src;
		ptr = (unsigned char *)dest;
		if (ptr > temp)
		{
			while (n-- > 0)
				ptr[n] = temp[n];
		}
		else
		{
			while (i < n)
			{
				ptr[i] = temp[i];
				i++;
			}
		}
	}
	return (dest);
}
