/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:46:36 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/31 18:23:09 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	printf("la stringa congiunta risulta %s", ft_strjoin(argv[1], argv[2]));
	return (0);
}
