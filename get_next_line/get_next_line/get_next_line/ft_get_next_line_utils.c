/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:00:41 by gvigano           #+#    #+#             */
/*   Updated: 2024/01/08 16:24:01 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ptr[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ptr[i++] = *s2;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}