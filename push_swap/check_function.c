/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:29:41 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/06 17:08:24 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_limits(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > ft_atoi("2147483647"))
			return (0);
		else if (ft_atoi(str[i]) < ft_atoi("-2147483648"))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char **argv)
{
	size_t	i;
	size_t	t;

	i = 1;
	t = 0;
	while (argv[i])
	{
		t = 0;
		while (argv[i][t])
		{
			if (argv[i][t] == ' ')
				return (0);
			t++;
		}
		i++;
	}
	return (1);
}

static int	check_duplicates(char **str)
{
	size_t	elem;
	char	**mat;
	size_t	i;

	elem = 0;
	while (str[elem])
		elem++;
	mat = ft_calloc(elem, sizeof(char *));
	elem = 0;
	while (str[elem])
	{
		i = 0;
		while (mat[i])
		{
			if (ft_atoi(str[elem]) == ft_atoi(mat[i++]))
			{
				free(mat);
				return (0);
			}
		}
		mat[i] = str[elem++];
	}
	free(mat);
	return (1);
}

static int	check_digits(char **argv)
{
	size_t	i;
	size_t	t;

	i = 1;
	while (argv[i])
	{
		t = 0;
		while (argv[i][t])
		{
			if ((argv[i][t] == '-' || argv[i][t] == '+')
			&& (argv[i][t + 1] < '0' || argv[i][t + 1] > '9'
			|| argv[i][t + 1] == '\0'))
				return (0);
			else if ((argv[i][t] >= '0' && argv[i][t] <= '9')
			&& ((argv[i][t + 1] < '0' || argv[i][t + 1] > '9'))
			&& (argv[i][t + 1] != ' ') && (argv[i][t + 1] != '\0'))
				return (0);
			else if (!ft_isdigit(argv[i][t]))
				return (0);
			t++;
		}
		i++;
	}
	return (1);
}

char	**check_parameter(int argc, char **argv)
{
	char	**str;

	if (check_digits(argv) == 0)
		return (NULL);
	str = fill_mat(argc, argv);
	if (!str)
		return (NULL);
	if (!check_duplicates(str) || !check_limits(str))
	{
		free_all(NULL, NULL, &str);
		return (NULL);
	}
	return (str);
}
