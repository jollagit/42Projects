/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:27:10 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 12:56:26 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*int	main(int argc, char *argv[])
{
	int	fd;
	
	if (argc != 3)
		return (0);
	fd = ft_atoi(argv[2]);
	ft_putchar_fd(argv[1][0], fd);
	return (0);
}*/

/*Description: Outputs the character ’c’ to the given file
descriptor.
Return value: None*/