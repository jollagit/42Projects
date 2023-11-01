/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:18:05 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 13:12:47 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*int	main(int argc, char *argv[])
{
	int	fd;
	
	if (argc != 3)
		return (0);
	fd = ft_atoi(argv[2]);
	ft_putstr_fd(argv[1], fd);
	return (0);
}*/

/*Description: Outputs the string ’s’ to the given file
descriptor.
Return value: None*/