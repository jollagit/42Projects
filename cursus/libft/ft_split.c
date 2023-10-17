/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:40 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/17 19:17:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	count;
	size_t	i;
	size_t	t;

	ptr = (char **) malloc (((ft_count(s, c)) + 1) * sizeof(char *));
	count = 0;
	i = 0;
	t = 0;
	while (s[t])
	{
		if (s[t] == c)
		{
			*ptr = ft_substr(s, t - count, count);
			i++;
			count = 0;
		}
		t++;
		count++;
	}
	return (ptr);
}
