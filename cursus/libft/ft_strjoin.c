/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:19:27 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/18 18:16:02 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	len_1;
	size_t	len_2;

	len_1 = strlen(s1);
	len_2 = strlen(s2);
	ptr = (char *) malloc ((len_1 + len_2 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len_1);
	ft_strlcat(ptr, s2, len_2 + len_1);
	ptr[len_2 + len_1 + 1] = '\0';
	return (ptr);
}
