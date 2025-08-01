/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:32:32 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/14 20:36:41 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>

char				*ft_itoa(int n);
int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);
int					ft_tolower(int i);
int					ft_toupper(int i);
long long int		ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				**ft_split(const char *s, char c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlcpy(char **dest, const char *src);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *big, const char *lit, size_t len);

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content);
void				ft_lstiter(t_list *lst, void (*f)(int));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_lstclear(t_list **lst);
t_list				*ft_lstmap(t_list *lst, int (*f)(int));

//	PRINTF Functions	//

int					ft_print_nbr(int n);
int					ft_print_str(char *s);
int					ft_print_ptr(void *ptr);
int					ft_print_unbr(unsigned int n);
int					ft_printf(const char *str, ...);
int					ft_print_hex(unsigned int n, const char c);

//	GET_NEXT_LINE Functions	//

size_t				ft_strlen_str(const char *s);
char				*get_next_line(int fd);
char				*ft_free_join(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);

#endif
