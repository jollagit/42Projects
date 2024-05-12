/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:40 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/02 16:05:43 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_ptr(char **ptr)
{
	if (ptr)
	{
		while (*ptr)
			free(*ptr++);
	}
}

static int	ft_countw(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (*s++ != '\0')
	{
		if ((*s == c && *(s -1) != c) || (*s == '\0' && *(s - 1) != c))
			count++;
	}
	return (count);
}

static char	**ft_fillptr(const char *s, char c, char **ptr, size_t nword)
{
	size_t	lenw;

	lenw = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (nword > 0)
	{
		if ((*s == c && *(s -1) != c) || (*s == '\0' && *(s - 1) != c))
		{
			*ptr = ft_substr(s - lenw, 0, lenw);
			if (!*ptr)
				return (NULL);
			ptr++;
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

	if (!s)
		return (NULL);
	nword = ft_countw(s, c);
	ptr = (char **) malloc ((nword + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	mat = ptr;
	while (*s == c)
		s++;
	ptr = ft_fillptr (s, c, ptr, nword);
	if (!ptr)
	{
		ptr = mat;
		ft_free_ptr(ptr);
		free(ptr);
		return (NULL);
	}
	*ptr = NULL;
	return (mat);
}

/*int	main(int argc, char *argv[])
{
	char	**str;
	size_t	i;
	
	if (argc != 3)
		return (0);
	str = ft_split(argv[1], argv[2][0]);
	printf("gli elementi sono:\n");
	i = 0;
	while (str[i])
	{
		printf("%s \n", str[i]);
		i++;
	}
	return (0);
}*/

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
Return value: The array of new strings resulting from the split,
NULL if the allocation fails.*/