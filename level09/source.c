int	secret_backdoor(void)
{
	char	buffer[128];

	fgets(buffer, 128, stdin);
	system(buffer);
	return (0);
}

int	set_username(char *username)
{
	char	buffer[144];

	memset(buffer, 0, 10);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buffer, 128, stdin);
}

int	handle_msg(void)
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

int	main(void)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();
	return (0);
}
