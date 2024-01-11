/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:00:41 by gvigano           #+#    #+#             */
/*   Updated: 2024/01/11 16:20:40 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	t;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s1)
		ptr[i++] = *(s1++);
	t = 0;
	while (*s2)
		ptr[i++] = *(s2++);
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