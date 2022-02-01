#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	test(char *buffer, unsigned int offset)
{
	char	*addr;

	addr = buffer - offset;

	if (addr <= 21)
		return (decrypt(rand()));

	func();
	((void (*) ())((addr << 2) + 0x80489f0))();
	return (0);
}

int		main(void)
{
	char	buffer[32];

	srand(time(0));
	puts("***********************************");
	puts("*		level03		**");
	puts("***********************************");

	printf("Password:");
	scanf("%d", buffer);
	test(&buffer[0], 0x1337d00d);
	return (0);
}
