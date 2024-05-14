/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:06:37 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/14 21:15:52 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#ifndef MAX
# define MAX 2048
#endif

static char	*ft_read_buffer(int fd, char *src)
{
	char		*tmp;
	ssize_t		current;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	current = 1;
	while (current != 0)
	{
		current = read(fd, tmp, BUFFER_SIZE);
		if (current == -1)
		{
			free(tmp);
			free(src);
			return (NULL);
		}
		tmp[current] = '\0';
		src = ft_free_join(src, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (src);
}

static char	*ft_search_extract(char *src)
{
	char	*line_found;
	size_t	i;

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

static char	*ft_rest_readed(char *src)
{
	int		t;
	int		i;
	char	*rest;

	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	rest = (char *)malloc((ft_strlen(src) -i +1) * sizeof(char));
	if (!rest)
		return (NULL);
	t = 0;
	i++;
	while (src[i])
		rest[t++] = src[i++];
	rest[t] = '\0';
	free(src);
	return (rest);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*src[MAX];
	size_t			i;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd == -42)
	{
		i = 0;
		while (src[i])
			free(src[i++]);
		return (NULL);
	}
	src[fd] = ft_read_buffer(fd, src[fd]);
	if (!src[fd])
		return (NULL);
	line = ft_search_extract(src[fd]);
	src[fd] = ft_rest_readed(src[fd]);
	if (!*line || !line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*int main (void)
{
	char	*line;
	int		file1;
	int		file2;

	if (!line)
		return (NULL);
	file1 = open("file1.txt", O_RDONLY);
	file2 = open ("file2.txt", O_RDONLY);
	printf("%d %d", file1, file2);
	line = get_next_line(file1);
	printf("%s", line);
	free(line);
	line = get_next_line(file2);
	printf("%s", line);
	free(line);
	
	return (0);
}*/

/*int	main(int argc, char *argv[])
{
	char	*line;
	FILE	*file;
	FILE	*file1;
	
	if (argc != 3)
		return (0);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (0);
	file = fopen(argv[1], "r");
	if (!file)
		return (0);
	file1 = fopen(argv[2], "r");
	if (!file)
		return (0);
	line = get_next_line(fileno(file));
	printf("%s", line);
	line = get_next_line(fileno(file1));
	printf("%s", line);
	line = get_next_line(fileno(file));
	printf("%s", line);
	line = get_next_line(fileno(file1));
	printf("%s", line);
	free(line);
	close(fileno(file));
	close(fileno(file1));
	return (0);
}*/

/*Per gestire piu' file descriptor allo stesso tempo
come richiesto, senza perdere traccia della lettura
di ogni fd, ho reso la mia variabile statica *src
una matrice che ha come indice l'fd in cui sto leggendo.
In questo modo sono sicura di star leggendo
in ogni chiamata dal file descriptor giusto,
potendo anche lavorare con fd diversi per ogni
chiamata, senza pero' perdere le letture di ognuno di essi.*/