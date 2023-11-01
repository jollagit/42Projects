/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:32:01 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 13:17:38 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		c;

	if (fd < 0)
		return ;
	nb = (long int)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb <= 9)
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
}
/*int	main(int argc, char *argv[])
{
	int	fd;
	
	if (argc != 3)
		return (0);
	fd = ft_atoi(argv[2]);
	ft_putnbr_fd(ft_atoi(argv[1]), fd);
	return (0);
}*/

/*Description: Outputs the integer ’n’ to the given file
descriptor.
Return value: None*/