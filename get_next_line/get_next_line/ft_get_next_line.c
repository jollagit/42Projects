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
	return (line);
}

// leggo una stringa di buffer_size caratteri dal file
static char	*ft_read_buffer(int fd, char *src)
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
			return (NULL);
		}
		tmp[current] = '\0';
		src = ft_strjoin(src, tmp);
	}
	free(tmp);
	return (src);
}

// estraggo dalla stringa letta la riga che trovo
static char	*ft_extract_line(char *src)
{
	char 	*line_found;
	int		i;

	if (!src)
		return (NULL);
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
static char	*ft_rest_readed(char *src)
{
	int		len;
	int		i;
	char	*rest;

	if (!src)
	{
		free(src);
		return (NULL);
	}
	len = ft_strlen(src);
	while (src[i] != '\n' && src[i])
		i++;
	len -= i;
	rest = (char *) malloc ((len + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	while (len != 0)
	{
		*rest = src[i];
		i++;
		len--;
	}
	return (rest);
}
