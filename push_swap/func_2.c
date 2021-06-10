#include "push_swap.h"

int ft_argv_len(char **argv)
{
    int i;

    i = 0;
    while(*argv)
    {
        i++;
        (argv)++;
    }
    return (i);
}