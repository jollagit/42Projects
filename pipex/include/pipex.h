#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

char	**find_args(char *argv);
int		check_fd(int fd, int direction);
char	**find_path(char **env, char *argv[]);
char	*check_path(char **paths, char *argv);
int		check_access(int argc, char *argv[]);

#endif