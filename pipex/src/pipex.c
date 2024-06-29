# include "pipex.h"

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

int main(int argc, char *argv[], char *env[])
{
	int		fd[2];

	if (argc < 4)
		return (1);
	if (!check_access(argc, argv))
		return (1);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	do_process1(argv, env, fd);
	return (0);
}
