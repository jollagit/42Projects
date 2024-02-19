/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:00:32 by gvigano           #+#    #+#             */
/*   Updated: 2024/02/19 18:08:34 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*src;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	src = ft_read_buffer(fd, src);
	if (!src)
		return (NULL);
	line = ft_search_extract(src);
	src = ft_rest_readed(src);
	if (!*line || !line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

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

char	*ft_search_extract(char *src)
{
	char 	*line_found;
	int		i;

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

char	*ft_rest_readed(char *src)
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


/*int	main(void)
{
	char	*line;

	line = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (0);
	line = ft_get_next_line(fileno(stdin));
	if (line != NULL)
		printf("%s", line);
	free(line);
	return (0);
}*/

/*int	main(int argc, char *argv[])
{
	char	*line;
	FILE	*file;
	
	if (argc != 2)
		return (0);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (0);
	file = fopen("hello.txt", "r");
	if (!file)
		return (0);
	line = get_next_line(fileno(file));
	printf("%s", line);
	free(line);
	return (0);
}*/

/* @ )L'istruzione 'static' mantiene in memoria il valore di una variabile
interna alla funzione dopo ogni chiamata, queste variabili hanno 
durata estesa a tutto il tempo di esecuzione del programma o alemeno
finche non vengono liberate attraverso free.
La struttura della funzione si basa su 3 altre funzioni
 1 ) Nella prima leggo una stringa di buffer_size caratteri dal file
usando una variabile char * temporanea,se non trovo alcun errore
in lettura allora concateno attraverso la funzione ft_strjoin
il contenuto precedentemente letto con quello esistente. 
 2 ) Nella seconda cerco in cio' che ho letto una riga e la estraggo 
assegnandola ad un'altra variabile.
 3 ) Nella terza, siccome sto ancora lavorando con la viabile src 
che comprende tutto quello che ho letto nella prima fuznione, elimino
la riga trovata dalla stringa letta in precedenza e ritorno il resto
di quello che ho già letto in modo da poterlo usare nella chiamata successiva.
*/