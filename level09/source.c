#include <stdio.h>

int			secret_backdoor(void)
{
	char	buffer[128];

	fgets(buffer, 128, stdin);
	system(buffer);
	return (0);
}

void		set_username(char *username)
{
	int		i = 0;
	char	buffer[144];

	memset(buffer, 0, 10);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buffer, 128, stdin);
	while (i < 40 && buffer[i] != 0)
	{
		*(username + 0x8c + i) = buffer[i];
		i++;
	}
	printf("", *(username + 0x8c)); // 0x165(%rip) 0xbfb
}

void 		set_msg(char *username)
{
	char	buff[1024];

	memset(buff, 0, 128);
	puts(""); //0x265(%rip) 0xbcd
	printf(""); //0x26b(%rip) 0xbdf
	fgets(buff, 1024, ""); // 0x201630(%rip) 0x201fb8
	strncpy(username, buff, *username+0xb4);
}

int			handle_msg(void)
{
	long	n;
	char	username[180];

	memset(username, 0, 40);
	n = 140;
	set_username(username);
	set_msg(username);
	puts(">: Msg sent!");

	return (0);
}

int		main(void)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();
	return (0);
}
