/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:47:17 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 19:08:57 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	len_tot;
	size_t	src_len;
	size_t	t;

	if (!dest || !src)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len)
		len_tot = size + src_len;
	else
		len_tot = dest_len + src_len;
	t = dest_len;
	while (*src != '\0' && (t + 1) < size)
	{
		dest[t] = *src;
		src++;
		t++;
	}
	dest[t] = '\0';
	return (len_tot);
}
/*int	main(int argc, char *argv[])
{
	char	str[50];
	size_t	len;
	
	if (argc > 0)
	{
		len = ft_strlen(argv[1]);
		ft_strlcpy(str, argv[1], (len + 1));
		ft_strlcat(str, argv[2], ft_atoi(argv[3]));
		printf("la mia stringa finale: %s \n", str);
	}
	return (0);
}*/

/*DESCRIPTION: strlcat()concatenate strings.
The strlcat() function appends the NUL-terminated
string src to the end of dst.  It will append at
most size - strlen(dst) - 1 bytes, NUL-terminating
the result.
RETURN VALUES: strlcat() functions return the
total length of the string they tried to create.
For strlcat() that means the initiallength
of dst plus the length of src.*/