/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/05 10:27:23 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(t_token *data, char *builtin, int fd1)
{
	if (ft_strncmp(builtin, "echo", ft_strlen(builtin)) == 0)
		ft_echo(data, fd1);
	if (ft_strncmp(builtin, "pwd", ft_strlen(builtin)) == 0)
		ft_pwd(data, fd1);
	if (ft_strncmp(builtin, "exit", ft_strlen(builtin)) == 0)
		ft_exit(data);
	if (ft_strncmp(builtin, "env", ft_strlen(builtin)) == 0)
		ft_env(data);
}
