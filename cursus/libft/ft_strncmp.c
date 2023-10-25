/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:56:07 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/25 19:13:50 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || n == 0)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && n > 1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
