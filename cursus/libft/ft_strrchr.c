/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:09 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/09 17:29:08 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int     i;
    int     t;

    i = 0;
    t = 0;
    while (s[i])
    {
        if (s[i] == c)
            t = i;
        i++;             
    }
    if (t = 0)
        return (0);
    else 
        return (s[t]);
}