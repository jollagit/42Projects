/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:15:44 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/27 17:55:24 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char	*line;
	char		*str;
	int			control;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *) malloc (BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	control = ft_read_line(fd, str);
	if (control <= 0)
	{
		free(line);
		return (NULL);
	}
	line = ft_extract_line(str);
	return (line);
}

char	ft_read_line(int fd, char *str)
{
	int		current;

	current = 1;
	while (str[current] != '\n' && current != 0)
	{
		current = read(fd, str, BUFFER_SIZE);
		if (current == -1)//error
			return (-1);
		else if (current == 0)//end of file
		{
			str[current] = '\0';
			return (0);
		}
		current++;
	}
	str[BUFFER_SIZE] = '\0';
	return (BUFFER_SIZE);
}

char	*ft_extract_line(char *str, int current)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return(str);
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
		printf("%s", line);
		line = ft_get_next_line(fd);
		printf("%s", line);
		line = ft_get_next_line(fd);
		printf("%s", line);
		line = ft_get_next_line(fd);
		printf("%s", line);
	}
	close (fd);
	return (0);
}

/*else if (line[current] == '\n')//end of line
		{
			line [current + 1] = '\0';
			return (current);
		}*/