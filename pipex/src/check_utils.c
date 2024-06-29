/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:03:49 by gvigano           #+#    #+#             */
/*   Updated: 2024/06/29 16:25:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_fd(int fd, int direction)
{
	if (dup2(fd, direction) == -1)
	{
		perror("dup2");
		return (0);
	}
	return (1);
}

int	check_access(int argc, char *argv[])
{
	if (access(argv[1], R_OK) == -1)
	{
		perror("access infile");
		return (0);
	}  
	if (access(argv[argc - 1], W_OK) && access(argv[argc - 1], F_OK) == 0)
	{
		perror("access outfile");
		return (0);
	}
	return (1);
}

char	*check_path(char **paths, char *argv)
{
	int		i;
	char	**str;
	char	*command;
	char	*tmp_comm;
	char	*result;

	i = 0;
	result = NULL;
	str = ft_split(argv, ' ');
	command = ft_strjoin("/", str[0]);
	while (paths[i])
	{
		tmp_comm = ft_strjoin(paths[i], command);
		if (access(tmp_comm, F_OK) == 0)
		{
			result = ft_strjoin(paths[i], command);
			free (tmp_comm);
			break ;
		}
		free (tmp_comm);
		i++;
	}
	free_all(str);
	free (command);
	return (result);
}
