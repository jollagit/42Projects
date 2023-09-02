#include<libft.h>

int     ft_strlcpy(char *dest, char *stc, int size)
{
    int i;

    i = 1;
    if (size == 0)
    {
        while (src[i])
            i++;
        return (i);
    }
    while (i <= size && stc[i])
    {
        dest[i] = src[i];
        i++;
    }
    if (i < size)
        dest[i] = '\0';
    while (stc[i] != '\0')
        i++;
    return (i);
}