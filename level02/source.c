#include <stdio.h>
#include <string.h>

int		main(void)
{
	FILE	*f;
	size_t	readed;
	char	buff_a[100];
	char	buff_b[48];
	char	buff_c[100];

	memset(buffer_a, 0, 12 * 4);
	memset(buffer_b, 0, 5);
	memset(buffer_c, 0, 12 * 4);

	if (!(f = fopen("/home/users/level03/.pass", "r")))
	{
		fwrite("ERROR: failed to open password file\n", 24, 1, stderr);
		exit(1);
	}

	readed = fread(buffer_b, 41, 1, f);
	buffer_b[strcspn(buffer_b, "\n")] = 0;

	if (readed != 41)
	{
		fwrite("ERROR: failed to open password file\n", 24, 1, stderr);
		fwrite("ERROR: failed to open password file\n", 24, 1, stderr);
		exit(1);
	}
	fclose(f);

	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");

	printf("--[ Username: ");
	fgets(buffer_a, 100, stdin);
	buffer_a[strcspn(buffer_a, "\n")] = 0;

	printf("--[ Password:");
	fgets(buffer_c, 100, stdin);
	buffer_c[strcspn(buffer_c, "\n")] = 0;

	puts("*****************************************");
	if (strncmp(buffer_b, buffer_c, 41) == 0)
	{
		printf("Greetings, %s!\n", buffer_a);
		system("/bin/sh");
	}

	printf(buffer_a);
	puts(" does not have access!");
	exit (1);
}
