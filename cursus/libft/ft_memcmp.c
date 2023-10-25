/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:52:04 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/25 19:37:29 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	if (!s1 || !s2 || n == 0)
		return (0);
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (n > 1)
	{
		if (*ptr_s1 != *ptr_s2)
			break ;
		ptr_s1++;
		ptr_s2++;
		n--;
	}
	return (*ptr_s1 - *ptr_s2);
}
