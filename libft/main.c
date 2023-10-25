/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:46:36 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/21 11:35:49 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("la mia %d \n", ft_atoi(argv[1]));
		printf("quella originale %d :", atoi(argv[1]));
	}
}
