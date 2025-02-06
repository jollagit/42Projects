/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_errors_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:40:21 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/06 11:40:35 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_var_name_error(char *var_name)
{
	ft_putstr_fd("\033[38;5;214mexport\033[0m: ", 2);
	ft_putstr_fd(var_name, 2);
	ft_putstr_fd(" :Not a valid var name\n", 2);
}

int	valid_var_name(char *var)
{
	size_t	i;

	if (!ft_isalpha(var[0]) && var[0] != '_')
	{
		print_var_name_error(var);
		return (0);
	}
	i = 1;
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
		{
			print_var_name_error(var);
			return (0);
		}
		i++;
	}
	return (1);
}
