/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:35:25 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/18 18:44:13 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t			len;
	size_t			start;
	size_t			end;

	start = 0;
	len = ft_strlen(s1);
	end = len;
	while (start < len && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (ft_strchr(set, s1[end]) != NULL)
		end--;
	len = end - start + 1;
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (len > 0)
	{
		*ptr = s1[start];
		ptr++;
		start++;
		len--;
	}
	*ptr = '\0';
	return (ptr);
}
