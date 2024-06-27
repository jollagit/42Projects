#include "pipex.h"

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
	free (paths);
	return (right_paths);
}

char	*check_path(char **paths, char *argv)
{
	int		i;
	char	**str;
	char	*command;
	char	*tmp_comm;

	i = 0;
	str = ft_split(argv, ' ');
	command = ft_strjoin("/", str[0]);
	while (paths[i])
	{
		tmp_comm = ft_strjoin(paths[i], command);
		if (access(tmp_comm, F_OK) == 0)
		{
			command = ft_strjoin(paths[i], command);
			free (str);
			free (tmp_comm);
			return (command);
		}
		i++;
	}
	free (str);
	free (tmp_comm);
	free (command);
	return (NULL);
}

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
