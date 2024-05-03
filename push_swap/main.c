/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:52 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/03 18:35:39 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*listA;
	t_list	*listB;
	char	**str;

	str = NULL;
	if (argc > 1)
		str = check_parameter(argc, argv);
	if (!str || check_input(argc, argv) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	listA = NULL;
	listB = NULL;
	listA = fill_list(listA, str);
	print_list(listA, listB);
	free_all(&listA, &listB, &str);
	return (0);
}