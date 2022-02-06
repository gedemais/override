#include <stdio.h>

int     main(void)
{
    int     i;
    char    buff[40];

    fgets(buff, 100, stdin);
    i = 0;
    while (strlen(buff) > i)
    {
        if (buff[i] > 64 || buff[i] <= 90)
            buff[i] ^= 0x20;               //tolower() on the upper charachter of the string
        i++;
    }
    printf(buff);
    exit(0);
}