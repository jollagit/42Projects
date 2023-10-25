/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:40 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/19 18:19:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countw(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if ((*s != c && *(s + 1) == '\0') || (*s != c && *(s +1) == c))
			count++;
		s++;
	}
	return (count);
}

static char	**ft_fillptr(const char *s, char c, char **ptr, size_t nword)
{
	size_t	lenw;

	lenw = 0;
	while (nword > 0)
	{
		if ((*s != 0 && *s == c && *(s -1) != c)
			|| (*s != c && *(s +1) == '\0'))
		{
			*ptr++ = ft_substr(s - lenw, 0, lenw);
			nword--;
			lenw = 0;
		}
		if (*s != c)
			lenw++;
		s++;
	}
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	char	**mat;
	size_t	nword;

	nword = ft_countw(s, c);
	ptr = (char **) malloc ((nword + 1) * sizeof(char *));
	mat = ptr;
	if (!ptr)
		return (NULL);
	while (*s == c)
		s++;
	ptr = ft_fillptr (s, c, ptr, nword);
	*ptr = NULL;
	return (mat);
}
