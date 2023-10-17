/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:25:44 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/17 18:33:17 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr_s;
	size_t				i;

	i = 0;
	ptr = (unsigned char *)dest;
	ptr_s = (const unsigned char *)src;
	while (i < n)
	{
		ptr[i] = ptr_s[i];
		i++;
	}
	return (dest);
}
