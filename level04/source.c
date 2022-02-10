#include <unistd.h>
#include <stdio.h>


void    prog_timeout()
{
    exit(1);
}

void   enable_timeout_cons()
{
    signal(15, &prog_timeout);
    alarm(60);
} 

void    clear_stdin(void)
{
	int	c;

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

int main()
{
    int     tmp;
    int     status;
    pid_t   addr;
    char    buff[32];

    addr = fork();
    memset(buff, 32, 0);
    tmp = 0;
    if (addr == 0)
    {
        prctl(1, 1);
        ptrace(0, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(buff);
    }
    else
    {
        while (ptrace(3, addr, 44, 0) != 0xb)
        {
            wait(&status);
            if ((tmp & 0x7f) == 0 || ((tmp & 0x7f) + 1) >> 1 > 0)
            {
                puts("child is exiting...");
                return (0);
            }
        }
        puts("no exec() for you");
        kill(addr, 9);
    }
    return (0);
}
