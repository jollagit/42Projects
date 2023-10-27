/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:35:25 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/27 19:44:35 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set, size_t len)
{
	size_t	i;
	
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}
static int	ft_end(char const *s1, char const *set, size_t len)
{
	size_t	i;
	
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i -1]) == NULL)
			break ;
		i++;
	}
	return (len -i -1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen (s1);
	start = ft_start(s1, set, len);
	end = ft_end(s1, set, len);
	len = end - start;
	i = 0;
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (len != 0)
	{
		ptr[i++] = s1[start];
		start++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
