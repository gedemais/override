#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int	test(int n, unsigned int offset)
{
	void	(*jmp)();
	void	*addr;

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

	decrypt(rand());
	out : return (0);
}

int		main(void)
{
	char	buffer[32];

	srand(time(0));
	puts("***********************************");
	puts("*		level03		**");
	puts("***********************************");

	printf("Password:");
	scanf("%d", (int*)buffer);
	test(*(int*)buffer, 0x1337d00d);
	return (0);
}
