#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	char	*line;
	int			control;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *) malloc (BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	control = ft_read_line(fd, line);
	if (control <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	ft_read_line(int fd, char *line)
{
	int		current;
	int		char_read;

	current = 0;
	while (current < BUFFER_SIZE)
	{
		char_read = read(fd, line + current, 1);
		if (line[current] == '\n')
			break ;
		current++;
	}
	line[current] = '\0';
	return (current);
}

int	main ()
{
	//int	fd;
	char *line;

	//if (argc != 2)
		//return (0);
	//fd = open(1, O_RDONLY);
	write (1, "HEllo", 5);
	printf("\nla lettura è: ");
	line = ft_get_next_line(1);
	if (line != NULL)
	{
		printf("%s\n", line);
		//line = ft_get_next_line(fd);
		//printf("%s\n", line);
		//line = ft_get_next_line(fd);
		//printf("%s\n", line);
		//line = ft_get_next_line(fd);
		//printf("%s\n", line);
	}
	//close (fd);
	return (0);
}
