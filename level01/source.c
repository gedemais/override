#include <stdio.h>
#include <stdlib.h>

char	a_user_name[100];

int		verify_user_name(char *input)
{
	return (strncmp(input, "admin ", 5));
}

int		verify_user_pass(char *input)
{
	return (strncmp(input, "dat_wil ", 7));
}

int		main(void)
{
	char	buffer[76];

	memset(buffer, 0, 10);
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username:");
	fgets(a_user_name, 160, stdin);
	if (verify_user_name(a_user_name) != 0)
	{
		puts("nope, incorrect username...\n");
		return (1);
	}

	printf("Enter Password:");
	fgets(buffer, 100, stdin);
	if (verify_user_pass(buffer) != 0)
	{
		puts("nope, incorrect password...\n");
		return (1);
	}
	return (0);
}
