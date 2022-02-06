#include <stdio.h>
#include <string.h>

int		auth(char *buffer, int serial)
{
	buffer += strcspn(buffer, "\n");
	buffer[0] = 0;

	strnlen(buffer, 32);
	return (0);
}

int		main(void)
{
	int		serial; // 0x28
	char	buffer[32]; // 0x2c

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

	if (auth(buffer, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
