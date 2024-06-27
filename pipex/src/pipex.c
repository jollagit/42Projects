# include "pipex.h"

static void	child_process(char *argv[], char *env[], int *fd, char *paths[])
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
	perror("execve cat");
	while (args[i])
		free(args[i++]);
	free (args);
	//free (paths);
}

static void	parent_process(char *argv[], char *env[], int *fd, char *paths[])
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
	perror("execve grep");
	while (args[i])
		free (args[i++]);
	free(args);
	//free(paths);
}

static void	do_process(char	*argv[], char *env[], int *fd)
{
	int		i;
	int		pid;
	char	**paths;

	i = 0;
	paths = find_path(env, argv);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
		child_process(argv, env, fd, paths);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(argv, env, fd, paths);
	}
	while (paths[i])
		free (paths[i++]);
	free (paths);
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
	do_process(argv, env, fd);
	return (0);
}
