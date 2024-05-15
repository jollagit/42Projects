/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:15:59 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/14 20:32:42 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_join(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	t;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc (sizeof(char)
			* (ft_strlen_str(s1) + ft_strlen_str(s2) + 1));
	if (!ptr)
		return (NULL);
	i = -1;
	t = 0;
	if (s1)
		while (s1[++i] != '\0')
			ptr[i] = s1[i];
	while (s2[t] != '\0')
		ptr[i++] = s2[t++];
	ptr[ft_strlen_str(s1) + ft_strlen_str(s2)] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen_str(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
