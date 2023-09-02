//#include<libft.h>

int     ft_strlcat(char *dest, char *src, int size)
{
    int     i;
    int     t;


    i = 0;
    t = 0;
    while (i < size && dest[i])
        i++;
    while (src[t] && (i + t + 1) < size)
    {
        dest[i + t] = src[t]
        t++;
    }
    if (i < size)
        dest[i + t] = '\0';
    return (i + ft_strlen(src));

}