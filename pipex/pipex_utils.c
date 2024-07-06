/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:51:55 by gvigano           #+#    #+#             */
/*   Updated: 2024/07/06 16:51:56 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_args(char *argv)
{
	char	**args;

	args = ft_split(argv, ' ');
	if (!args)
	{
		perror("find_args");
		exit(1);
	}
	return (args);
}

void	free_all(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**find_path(char **env, char *argv[])
{
	int		i;
	char	**paths;
	char	**right_paths;

	i = 0;
	paths = NULL;
	right_paths = malloc (sizeof (char *) * 3);
	if (!right_paths)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split((env[i] + 5), ':'); 
			break;
		}
		i++;
	}
	right_paths[0] = check_path(paths, argv[2]);
	right_paths[1] = check_path(paths, argv[3]);
	right_paths[2] = NULL;
	free_all(paths);
	return (right_paths);
}
