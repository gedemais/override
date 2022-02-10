#include <stdio.h>
#include <string.h>

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

int		auth(char *buff, int serial)
{
	char	c;   //-0x10(ebp)
	int		tmp;
	int		tmp2;
	int		tmp3;
	int		i; //-0x14(ebp)
	int		len; //-0xc(ebp)

	buff[strcspn(buff, "\n") - 1] = 0;
	len = strnlen(buff, 32);
	if (len != 0)
		len += 4;
	if (len > 5)
		return (1);
	if (ptrace(0, 0, 1, 0) == -1)
	{
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
	}
	else
	{
		c = (buff[2] ^ 0x1337) + 0x5eeded;
		i = 0;
		while (len > i)
		{
			if (buff[i] < 0x1f)
				return (1);
			tmp = c ^ buff[i];
			tmp2 = tmp * 0x88233b2b;
			tmp3 -= 0x88233b2b;
			tmp3 = tmp >> 1;
			tmp3 += 0x88233b2b;
			tmp3 = tmp * 0x539;
			tmp -= tmp3;
			c += tmp;
			i++;
		}
		if (serial == c)
			return (0);
	}
	return (1);
}

int		main(void)
{
	int		serial; // 0x28
	char	buff[32]; // 0x2c

	puts("***********************************");
	puts("*		level06		  *");
	puts("***********************************");

	printf("-> Enter Login: ");
	fgets(buff, 32, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");

	printf("-> Enter Serial: ");
	scanf("%d", &serial);

	if (auth(buff, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
