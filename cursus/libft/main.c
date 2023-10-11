/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:46:36 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/11 17:33:34 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char	*c;

	if (argc > 0)
	{
		printf("mio: %s \n", ft_strchr("Ciao mi chiamo chiara", ' '));
		printf("originale: %s", strchr("Ciao mi chiamo chiara", ' '));
	}
	argv[2] = "aaaaaa";
}
