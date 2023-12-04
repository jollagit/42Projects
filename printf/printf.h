#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_print_nbr(int n);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_percent(void);
int	ft_print_ptr(const void *ptr);
int	ft_print_unbr(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_print_hex(unsigned int n, const char c);
int	ft_search_format(va_list ptr, const char s);

#endif

