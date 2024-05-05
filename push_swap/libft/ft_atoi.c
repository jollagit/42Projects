/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:43:03 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/05 17:40:39 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	long long int	base;
	size_t			sign;

	if (!str)
		return (0);
	sign = 1;
	base = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		base = base * 10 + (*str - '0');
		str++;
	}
	return (base * sign);
}
/*int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("il carattere diventa: %d", ft_atoi(argv[1]));
	printf("\n con l'originale: %d", atoi(argv[1]));
	return (0);
}*/
/*DESCRIPTION: The atoi() function converts the initial
portion of the string pointed to by nptr to int.
RETURN VALUE: The converted value.*/
