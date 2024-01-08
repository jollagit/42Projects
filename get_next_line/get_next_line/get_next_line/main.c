/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:00:17 by gvigano           #+#    #+#             */
/*   Updated: 2024/01/08 13:55:25 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	FILE	*file;
	int		fd;
	char	*line;

	if (argc < 2)
		return (0);
	file = fopen(argv[1], O_RDONLY);
	if (file == NULL)
	{
		printf("Errore nell'aprire il file");
		return (1);
	}
	fd = fileno(file);
	line = ft_get_next_line(fd);
	if (line != NULL)
		printf("line : %s", line);
	free (line);
	close(fd);
	return (0);
}
