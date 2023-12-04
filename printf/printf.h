#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_print_nbr(int n);
int	ft_print_str(char *s);
int	ft_print_ptr(const void *ptr);
int	ft_print_unbr(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_print_hex(unsigned int n, const char c);

#endif