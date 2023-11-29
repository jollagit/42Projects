#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t		ft_strlen(const char *s);
char		*ft_get_next_line(int fd);
static char	*ft_read_buffer(int fd, char *src);
char		*ft_strjoin(const char *s1, const char *s2);
static char	*ft_extract_line(char *src);

#endif