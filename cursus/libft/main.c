/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:46:36 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 19:44:31 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("il mio carattere nuovo: %d", ft_toupper(argv[1][0]));
		printf("\n l'originale: %d", toupper(argv[1][0]));
	}
	return (0);
}
	
