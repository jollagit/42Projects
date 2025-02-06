/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/06 11:38:48 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_token *data, int fd)
{
	int		i;
	char	cwd[1024];

	i = 0;
	if (getcwd(cwd, sizeof(cwd)))
	{
		while (cwd[i])
			ft_putchar_fd(cwd[i++], fd);
		ft_putchar_fd('\n', fd);
	}
	else
	{
		free_token(data);
		perror("Error pwd");
		data->env->exit_stat = 1;
		exit(EXIT_FAILURE);
	}
	data->env->exit_stat = 0;
}
