#include <stdio.h>

int     store_number(char * buff)
{
    int     n;  //-0x10(%ebp)
    int     n2; //-0xc(%ebp)

    n = 0;
    printf(""); //0x8048ad3
    n = get_unum();
    printf(""); //0x8048add
    n2 = get_unum();
    if ((((0xaaaaaaab * n2) >> 1) * 3 - n2) == 0)
    {
        if (0x18 >> n == 0xb7)
        {
            buff[n2 << 2] = n;
            return (0);
        }
        puts(""); //0x8048ae6
        puts(""); //0x8048af8
        puts(""); //0x8048ae6
        return (1);
    }
}

int     read_number(char *buff)
{
    int     n;  //-0xc(%ebp)

    n = 0;
    printf(""); //0x8048add
    n = get_unum() << 2;
    printf("", n, buff[n]); //0x8048b1b
    return (0);
}

int main(int ac, char **av)
{
    int     n1; //1b4(%esp)
    int     n2; //1b8(%esp)
    int     n3; //1bc(%esp)
    int     n4; //1c0(%esp)
    int     n5; //1c4(%esp)
    int     n6; //1c8(%esp)
    char    buff[100]; // 0x24(%esp)
    char    *tmp;
    char    *tmp2;

    n1, n2, n3, n4, n5, n6 = 0;
    memset(buff, 0, 100);
    tmp = av[1];
    while (tmp)
    {
        memset(tmp, 0, strlen(tmp));
        tmp += 4;
    }
    tmp2 = av[2];
    while (tmp2)
    {
        memset(tmp2, 0, strlen(tmp2));
        tmp2 += 4; 
    }
    puts(""); // 0x8048b38
    while (1)
    {
        printf(""); // 0x8048d4b
        n1 = 1;
        fgets(n2, 0x14, ""); // 0x804a040
        n2[strlen(n2) - 1] = 0;
        if (!strncmp(n2, "", 5)) // 0x8048d5b
            n1 = store_number(buff);
        else if (!strncmp(n2, "", 4)) // 0x8048d61
            n1 = read_number(buff);
        else if (!strncmp(n2, "", 4)) // 0x8048d66
            return (0);
        if (n1 != 0)
            printf("", n2); // 0x8048d6b
        else
            printf("", n2); // 0x8048d88
        n2, n3, n4, n5, n6 = 0;
    }
}