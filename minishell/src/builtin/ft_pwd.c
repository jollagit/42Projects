/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/04 16:56:12 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_token *data, int fd)
{
	int		i;
	char	cwd[PATH_MAX];
	
	i = 0;
	if (getcwd(cwd, sizeof(cwd)))
	{
		while(cwd[i])
			ft_putchar_fd(cwd[i++], fd);
		ft_putchar_fd('\n', fd);
	}
	else
	{
		free_token(data);
		perror("Error pwd");
		exit(EXIT_FAILURE);
	}
}
