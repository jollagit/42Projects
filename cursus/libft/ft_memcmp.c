/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:52:04 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/18 17:18:44 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (--n != 0)
	{
		if (*ptr_s1 != *ptr_s2)
			break;
		ptr_s1++;
		ptr_s2++;
	}
	return (*ptr_s1 - *ptr_s2);
}
