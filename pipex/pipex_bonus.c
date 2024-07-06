/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:22:27 by gvigano           #+#    #+#             */
/*   Updated: 2024/07/06 18:30:31 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process1(char *argv[], char *env[], int *fd, char *paths[])
{
	int		i;
	int		infile;
	char	**args;

	i = 0;
	close(fd[0]);
	infile = open (argv[1], O_RDONLY, 0777);
	if (!check_fd(infile, 0))
		return ;
	if (!check_fd(fd[1], 1))
		return ;
	close(fd[1]);
	args = find_args(argv[2]);
	execve(paths[0], args, env);
	perror("execve cmd1");
	free_all(args);
	exit(EXIT_FAILURE);
}

static void	child_process2(char *argv[], char *env[], int *fd, char *paths[])
{
	int		i;
	int		outfile;
	char	**args;

	i = 0;
	close(fd[1]);
	if (!check_fd(fd[0], 0))
		return ;
	close(fd[0]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("open outfile");
		return ;
	}
	if (!check_fd(outfile, 1))
		return ;
	close(outfile);
	args = find_args(argv[3]);
	execve(paths[1], args, env);
	perror("execve cmd2");
	free_all(args);
	exit(EXIT_FAILURE);
}

static void	do_process2(char *argv[], char *env[], int *fd, char **paths)
{
	int	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		return ;
	}
	if (pid2 == 0)
		child_process2(argv, env, fd, paths);
	else
	{
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
}

static void	do_process1(char *argv[], char *env[], int *fd)
{
	int		i;
	int		pid1;
	char	**paths;

	i = 0;
	paths = find_path(env, argv);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		return ;
	}
	if (pid1 == 0)
		child_process1(argv, env, fd, paths);
	else
		do_process2(argv, env, fd, paths);
	free_all(paths);
}

static void	here_doc(const char *limiter)
{
	char	*line;
	int		fd[2];

	line = NULL;
	fd = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd < 0)
		perror("open file");
	while (1)
	{
		line = get_next_line(fileno(argv[1]));
	}
	
}	

static void pipex(int argc, char *argv[], char *env[], int i)
{
	int		infile;
	int		outfile;

	if (strcmp(argv[1], "here_doc") == 0)
	{
		i = 3;
		here_doc(argv[2]);
		infile = open(".here_doc_tmp", O_RDONLY);
		if (infile < 0)
			perror("open infile");
		outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (outfile)
			perror("open outile");
	}
	else
	{
		i = 2;
		infile = open(argv[1], O_RDONLY);
        if (infile < 0) error_exit("open");
        outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (outfile < 0) error_exit("open");
	}
    dup2(infile, STDIN_FILENO);
    close(infile);
}

int	main(int argc, char *argv[], char *env[])
{
	int	i;

	i = 0;
	pipex(argc, argv, env, i);
}

/*if (!check_access(argc, argv))
		return (1);
if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
do_process1(argv, env, fd);*/