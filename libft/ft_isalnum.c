//#include<libft.h>
#include<stdlib.h>
#include <unistd.h>

int     ft_isalnum(char i)
{
    if((i >= '0' && i <= '9') || ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')))
        return (1);
    return (0);
}

int     main(int argc, char *argv[])
{
    if(argc < 2)
        return (0);
    if(ft_isalnum(argv[1][0]))
    {
        write(1, "1", 1);
        return (0);
    }
    write (1, "0", 1);
}