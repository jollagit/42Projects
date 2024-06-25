/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:20:36 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 13:15:28 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*int	main(int argc, char *argv[])
{
	int	fd;
	
	if (argc != 3)
		return (0);
	fd = ft_atoi(argv[2]);
	ft_putendl_fd(argv[1], fd);
	return (0);
}*/

/*Description: Outputs the string ’s’ to the given file descriptor
followed by a newline.
Return value: None*/