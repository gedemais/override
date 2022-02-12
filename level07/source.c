#include <stdio.h>
#include <unistd.h>

void    prog_timeout()
{
    exit(1);
}

void        clear_stdin(void)
{
	int     c;

	c = 0;
	while (1)
	{
		c = getchar();
		if (c == 10 || c == 255)
			return ;
	}
}

unsigned int	    get_unum(void)
{
	unsigned int	n = 0;

	fflush(stdout);
	scanf("%u", &n);
	clear_stdin();

	return (n);
}

int                 store_number(u_int8_t *buff)
{
    u_int8_t        *tmp;
    unsigned int    n = 0;  //-0x10(%ebp)
    unsigned int    i = 0; //-0xc(%ebp)

    printf(" Number: "); //0x8048ad3
    n = get_unum();
    printf(" Index: "); //0x8048add
    i = get_unum();
    if ((i - (((0xaaaaaaab * i) >> 1) * 3)) != 0 && n >> 0x18 != 0xb7) // if (i % 3 == 0 && n >> 0x18 != 0xb7)
    {
        memcpy((buff + i * 4), &n, 4);
        return (0);
    }
    puts(" *** ERROR! ***"); //0x8048ae6
    puts("   This index is reserved for wil!"); //0x8048af8
    puts(" *** ERROR! ***"); //0x8048ae6
    
    return (1);
}

int         read_number(char *buff)
{
    int     i;  //-0xc(%ebp)

    i = 0;
    printf(" Index:"); //0x8048add
    i = get_unum();
    printf(" Number at data[%u] is %u\n", i, buff[i]); //0x8048b1b
    return (0);
}

int             main(int ac, char **av, char **env)
{
    int         ret; //1b4(%esp)
    char        cmd_buff[20] = {0}; //1b8(%esp)
    u_int8_t    buff[400] = {0}; // 0x24(%esp)
    char        *tmp;
    char        *tmp2;

    tmp = av;
    tmp2 = env;
    while (*tmp)
    {
        memset(*tmp, 0, strlen(*tmp));
        *tmp++;
    }
    while (*tmp2)
    {
        memset(*tmp2, 0, strlen(*tmp2));
        *tmp2++; 
    }
    puts("----------------------------------------------------\n\
          Welcome to wil's crappy number storage service!   \n\
        ----------------------------------------------------\n\
         Commands:                                          \n\
            store - store a number into the data storage    \n\
            read  - read a number from the data storage     \n\
            quit  - exit the program                        \n\
        ----------------------------------------------------\n\
           wil has reserved some storage :>                 \n\
           ----------------------------------"); // 0x8048b38
    while (1)
    {
        printf("Input command: "); // 0x8048d4b
        ret = 1;
        fgets(cmd_buff, 20, stdin); // 0x804a040
        cmd_buff[strlen(cmd_buff) - 1] = 0;
        if (!strncmp(cmd_buff, "store", 5)) // 0x8048d5b
            ret = store_number(buff);
        else if (!strncmp(cmd_buff, "read", 4)) // 0x8048d61
            ret = read_number(buff);
        else if (!strncmp(cmd_buff, "quit", 4)) // 0x8048d66
            return (0);
        if (ret == 0)
            printf(" Completed %s command successfully\n", cmd_buff); // 0x8048d88
        else
            printf(" Failed to do %s command\n", cmd_buff); // 0x8048d6b
        memset(&cmd_buff, 0, 20);
    }
    return 0;
}