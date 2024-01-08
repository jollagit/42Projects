/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:00:32 by gvigano           #+#    #+#             */
/*   Updated: 2024/01/08 16:31:20 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char	*line;
	char		*src;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	src = ft_read_buffer(fd, src);
	if (!src)
		return (NULL);
	line = ft_extract_line(src);
	src = ft_rest_readed(src);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// leggo una stringa di buffer_size caratteri dal file
char	*ft_read_buffer(int fd, char *src)
{
	char	*tmp;
	int		current;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	current = 1;
	while (tmp[current] != '\n' && current != 0)
	{
		current = read(fd, tmp, BUFFER_SIZE);
		if (current == -1)
		{
			free(tmp);
			free(src);
			return (NULL);
		}
		tmp[current] = '\0';
		src = ft_strjoin(src, tmp);
	}
	free(tmp);
	return (src);
}

// estraggo dalla stringa letta la riga che trovo
char	*ft_extract_line(char *src)
{
	char 	*line_found;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	line_found = (char *)malloc((i + 2) * sizeof(char));
	if (!line_found)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i])
	{
		line_found[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		line_found[i] = src[i];
		i++;
	}
	line_found[i] = '\0';
	return (line_found);
}

//elimino la riga trovata dalla stringa letta in precedenza e ritorno il resto di quello che ho già letto
char	*ft_rest_readed(char *src)
{
	int		t;
	int		i;
	char	*rest;

	if (!src)
	{
		free(src);
		return (NULL);
	}
	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	rest = (char *)malloc((ft_strlen(src) -i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	t = 0;
	while (src[i])
		rest[t++] = src[i++];
	free(src);
	return (rest);
}
