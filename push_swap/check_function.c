/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:29:41 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/03 18:35:48 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int argc, char **argv)
{
	size_t	i;
	size_t	t;
	
	if (argc > 2)
	{
		i = 1;
		t = 0;
		while (argv[i])
		{
			while (argv[i][t])
			{
				if (argv[i][t] == ' ')
					return (0);
				t++;
			}
			i++;
		}
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
			if ((argv[i][t] == '-' || argv[i][t] == '+') && (argv[i][t + 1] < '0'
			|| argv[i][t + 1] > '9' || argv[i][t + 1] == '\0'))
				return (0);
			if ((argv[i][t] >= '0' && argv[i][t] <= '9') && ((argv[i][t + 1] < '0'
			|| argv[i][t + 1] > '9')) && (argv[i][t + 1] != ' ') && (argv[i][t + 1] != '\0'))
				return (0);
			t++;
		}
		i++;
	}
	return (1);
} 

char	**check_parameter(int argc, char **argv)
{
	int		i;
	size_t	t;
	char	**str;

	t = 0;
	i = 1;
	if (check_digits(argv) == 0)
		return (NULL);
	if (argc > 2)
	{
		str = malloc((argc) * (sizeof(char *)));
		if (!str)
			return (NULL);
		while (i < argc)
			ft_strlcpy(&str[t++], argv[i++]);
	}
	else 
		str = ft_split(argv[1], ' ');
	if (check_duplicates(str) == 0)
	{
		free_all(NULL, NULL, &str);
		return (NULL);
	}
	return (str);
}
