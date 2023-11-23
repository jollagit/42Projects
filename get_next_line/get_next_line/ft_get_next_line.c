#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

int	ft_read_line(int fd, char *line);

char	*ft_get_next_line(int fd)
{
	char	*line;
	int		control;

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

// controllo se ho raggiunto la fine della riga su cui sto lavorando
int	ft_end_line(char element)
{
	if (element == '\n')
			return (1);
	return (0);
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

int	main (int argc, char *argv[])
{
	int	fd;
	char *line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = ft_get_next_line(fd);
	if (line != NULL)
	{
		printf("\n%s", line);
		line = ft_get_next_line(fd);
		printf("\n%s", line);
	}
	close (fd);
	return (0);
}
