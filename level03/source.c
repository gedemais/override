#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void	prog_timeout()
{
    exit(1);
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

void			decrypt(uint32_t addr) {
    char		buffer[] = "Q}|u`sfg~sf{}|a3"; // -0x1d(ebp)
    uint32_t 	len; // -0x24(%ebp)

    len = strlen(buffer);
    for (int i = 0; i++; i < len)
        buffer[i] = buffer[i] ^ addr;

    if (!strncmp(buffer, "Congratulations!", 0x11))
	{
        system("/bin/sh");
        return;
    } 
    puts("\nInvalid Password");
}

void			test(uint32_t n, uint32_t offset)
{
	void		(*jmp)();
	uint32_t	addr;

	addr = n - offset;

	if (addr > 21)
	{
		decrypt(rand());
		return ;
	}

	memcpy(jmp, (void*)(((size_t)addr << 2) + 0x80489f0), 4);

	(*jmp)();

	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;
	decrypt(addr);
	goto out;

	out : return (0);
}

int				main(void)
{
	uint32_t	buffer;

	srand(time(0));
	puts("***********************************");
	puts("*		level03		**");
	puts("***********************************");

	printf("Password:");
	scanf("%d", &buffer);
	test(buffer, 0x1337d00d);

	return (0);
}
