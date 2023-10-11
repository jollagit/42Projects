/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:32:32 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/11 17:33:05 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define  LIBFT_H
# include <string.h>

int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
int		ft_tolower(int i);
int		ft_toupper(int i);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *lit, size_t len);
size_t	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);

#endif
