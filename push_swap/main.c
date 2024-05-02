/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:52 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/02 16:05:30 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*listA;
	t_list	*listB;
	char	**str;
	int		i;

	str = NULL;
	i = 0;
	if (argc > 1)
		str = check_parameter(argc, argv);
	if (!str)
	{
		while (str[i])
			free(str[i++]);
		ft_printf("Error");
		free (str);
		return (0);
	}
	listA = NULL;
	listB = NULL;
	i = 0;
	listA = fill_list(listA, str);
	print_list(listA, listB);
	while (str[i])
		free(str[i++]);
	free (str);
	ft_lstclear(&listA);
	ft_lstclear(&listB);
	return (0);
}


/*static void	ft_free_str(char **str)
{
	if (str)
	{
		while (*str)
			free(*str++);
	}
}*/