/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2024/10/22 15:40:14 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// implementare redirection prima di fare il fork per i processi -->
void	do_command(t_token *data, char *env[])
{
	int		pid;
	int		fdin;
	int		fdout;
	int 	tmpin;
	int 	tmpout;

	tmpin = dup(0);
	tmpout = dup(1);
	if (data->rd != NULL)
		fdin = open(data->rd->name, O_RDONLY);
	else
		fdin = dup(tmpin);
	while (data->value != NULL)
	{
		dup2(fdin, 0);
		close (fdin);
		if (data->next->value == NULL)
		{
			if (data->rd != NULL)
				fdout = open(data->rd->name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			else
				fdout = dup(tmpout);
		}
		else
		{
			int	fd[2];

			pipe(fd);
			fdout = fd[1];
			fdin = fd[0];
		}
		dup2(fdout, 1);
		close(fdout);
		pid = fork();
		if (pid == 0)
		{
			execve(data->value[0], data->value, env);
			perror("error");
			exit(1);
		}
		data = data->next;
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	waitpid(pid, 0, 0);
}

// if (!background)
// 		waitpid(pid, NULL);