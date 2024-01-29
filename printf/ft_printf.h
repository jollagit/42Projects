/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:01:53 by gvigano           #+#    #+#             */
/*   Updated: 2024/01/29 14:25:56 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_print_nbr(int n);
int	ft_print_str(char *s);
int	ft_print_ptr(void *ptr);
int	ft_print_unbr(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_print_hex(unsigned int n, const char c);

#endif