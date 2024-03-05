/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:38 by gvigano           #+#    #+#             */
/*   Updated: 2024/03/05 17:52:21 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>

size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);

#endif