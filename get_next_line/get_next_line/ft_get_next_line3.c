/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:46:23 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/27 18:00:48 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char *line;
	char		*tmp;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read_buffer(fd, tmp);
	
}

char	ft_read_buffer(int fd, char *tmp)
{
	int	i;

	i = 1;
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return(NULL);
	while (tmp[i] != '\n' && i != 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

char	*ft_return_line(char *tmp)
{
	char	*str;

	if (!tmp)
		return (NULL);
	
}