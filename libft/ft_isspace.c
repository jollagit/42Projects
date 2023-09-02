#include<libft.h>

int     ft_isspace(int i)
{
    if (i == ' ' || i == '\t' || i == '\v' || i == '\n' || i == '\f' || i == '\r')
        return (1);
    return (0);
}