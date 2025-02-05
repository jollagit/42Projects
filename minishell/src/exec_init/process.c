/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/04 15:21:51 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// DA SPOSTARE LE FUNZIONI VOID NON STATICHE IN UN ALTRO FILE
void	check_pid(t_token *data, int pid)
{
	if (pid < 0)
	{
		free_token(data);
		perror("Fork Error");
		exit(EXIT_FAILURE);
	}
}

void	handle_pipe(t_token *data, int fd[2])
{
	if (pipe(fd) < 0)
	{
		free_token(data);
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
}

static void	child_process(t_token *data, int fd0, int fd1)
{
	if (data->next)
	{
		close(fd0);
		if (dup2(fd1, STDOUT_FILENO) < 0)
		{
			free_token(data);
			perror("Dup2 child pipe write error");
			exit(EXIT_FAILURE);
		}
		close (fd1);
	}
	if (execve(data->value[0], data->value, data->env->var) == -1)
	{
		free_token(data);
		perror("execute error");
		exit(EXIT_FAILURE);
	}
}

static void	parent_process(t_token *data, int pid, int fd0, int fd1)
{
	int	status;

	if (data->next)
	{
		close(fd1);
		if (dup2(fd0, STDIN_FILENO) < 0)
		{
			free_token(data);
			perror("Dup2 parent pipe read error");
			exit(EXIT_FAILURE);
		}
		close(fd0);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		data->exit_stat = WEXITSTATUS(status);
}

static void	handle_process(t_token *data, int fd0, int fd1)
{
	int			pid;

	pid = fork();
	check_pid(data, pid);
	if (pid == 0)
	{
		if (check_if_builtin(data->value[0]))
		{
			execute_builtin(data, data->value[0], fd1);
			free_token(data);
			exit(0);
		}
		else
			child_process(data, fd0, fd1);
	}
	else
		parent_process(data, pid, fd0, fd1);
}

void	do_command(t_token *data)
{
	int			fdin;
	int			fd[2];
	int			fdout;

	fdin = dup(STDIN_FILENO);
	fdout = dup(STDOUT_FILENO);
	while (data && data->value[0])
	{
		handle_redir(data);
		if (data->next)
			handle_pipe(data, fd);
		if (check_if_builtin(data->value[0]) && !data->next)
		{
			execute_builtin(data, data->value[0], 1);
			return;
		}
		else
			handle_process(data, fd[0], fd[1]);
		data = data->next;
	}
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fdin);
	close(fdout);
}
