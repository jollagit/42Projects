/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:09 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/20 16:17:28 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s != '\0')
		s++;
	while (s)
	{
		if (*s == c)
			return ((char *) s);
		s--;
	}
	if (*s == c)
		return ((char *) s);
	return (NULL);
}
