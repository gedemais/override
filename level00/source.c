#include <stdio.h>

int		main(void)
{
	int	buffer[8]; // 32 octets, sub 0x20,%esp

	puts("***********************************");
	puts("* 	     -Level00 -		  *");
	puts("***********************************");

	printf("Password:");
	scanf("%d", buffer);

	if (buffer[0] != 0x149c)
	{
		puts("Invalid Password!");
		return (1);
	}
	puts("Authenticated!");
	system("/bin/sh");
	return (0);
}
