#include <stdio.h>

typedef struct s_user
{
	char	username[180];
	long	n;
} t_user;

int			secret_backdoor(void)
{
	char	buffer[128];

	fgets(buffer, 128, stdin);
	system(buffer);

	return (0);
}

void		set_username(t_user *user)
{
	int		i = 0;
	char	buffer[144];

	memset(buffer, 0, 10);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buffer, 128, stdin);

	while (i < 40 && buffer[i] != 0)
	{
		*(user->username + 0x8c + i) = buffer[i];
		i++;
	}
	
	printf("", *(user->username + 0x8c)); // 0x165(%rip) 0xbfb
}

void 		set_msg(t_user *user)
{
	char	buff[1024];

	memset(buff, 0, 128);
	puts(">: Msg @Unix-Dude"); //0x265(%rip) 0xbcd
	printf(">>: "); //0x26b(%rip) 0xbdf
	fgets(buff, 1024, stdin); // 0x201630(%rip) 0x201fb8
	strncpy(user->username, buff, user->n);
}

int			handle_msg(void)
{
	t_user 	user;

	memset(user.username+0x8c, 0, 40);
	user.n = 140;
	set_username(&user);
	set_msg(&user);
	puts(">: Msg sent!");

	return (0);
}

int		main(void)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();

	return (0);
}
