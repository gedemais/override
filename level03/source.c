#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void				clear_stdin(void)
{
	int				c;

	c = 0;
	while (c != 255)
	{
		c = getchar();
		if (c == 10)
			return ;
	}
}

unsigned int		get_unum(void)
{
	unsigned int	n;;

	fflush(stdout);
	scanf("%u", n);
	clear_stdin();

	return (n);
}

void				decrypt(int n)
{
	
}

int					test(int n, unsigned int offset)
{
	void			(*jmp)();
	void			*addr;

	addr = (void*)((size_t)n - (size_t)offset);

	if (addr > (void*)21)
		return (decrypt(rand()));

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

int					main(void)
{
	char			buffer[32];

	srand(time(0));
	puts("***********************************");
	puts("*		level03		**");
	puts("***********************************");

	printf("Password:");
	scanf("%d", (int*)buffer);
	test(*(int*)buffer, 0x1337d00d);

	return (0);
}
