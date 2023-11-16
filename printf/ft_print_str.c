/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:39:35 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/16 11:34:05 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_print_str(char *s)
{
	size_t	t;

	t = 0;
	if (!s)
		return (0);
	while (s[t])
	{
		write (1, &s[t], 1);
		t++;
	}
	return (t);
}