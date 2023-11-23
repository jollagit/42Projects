#include <stdio.h>
#include <unistd.h>

char	ft_get_next_line(int fd)
{
	FILE	*fptr;
	char	line[50];
	int		buffer;
	int		char_read;

	if (fd < 0)
		return (NULL);
	buffer = 50;
	char_read = 0;
	fptr = fopen("hello.txt", "r");
	if (fptr)
	{
		char_read = read(fd, line, 1);
		while (!feof(fptr) && line[char_read] != '\0')
		{
			line[char_read] = '\0';
			write(fd, &line[char_read], 1);
		}
		char_read++;
	}
	else
	{
		printf("ho trovato un errore nel file");
		exit (-1);
	}
	fclose(fptr);
	return (0);
}