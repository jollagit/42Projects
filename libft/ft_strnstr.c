/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:18:34 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/11 17:24:15 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	t;

	if (*lit == '\0' || big == lit)
		return ((char *) big);
	while (*big != '\0' && len > 0)
	{
		t = 0;
		while (*(big + t) != '\0' && lit[t] != '\0'
			&& *(big + t) == lit[t] && len > 0)
		{
			t++;
			len--;
		}
		if (lit[t] == '\0')
			return ((char *) big);
		len--;
		big++;
	}
	return (NULL);
}
