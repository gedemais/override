void    log_wrapper()
{

}

int         main(int ac, char **av)
{
    int     fd; // -0x88(%rbp)
    int     fd2; // -0x80(%rbp)
    int     fd3 = -1; // -0x78(%rbp)
    char    buff[104] = {0};

    if (ac != 2) // $0x2,-0x94(%rbp)
        printf("Usage: %s filename\n", av[0]); // 0x400d57,  -0xa0(%rbp)
        
    fd = fopen("./backups/.log", "w");

    if (fd == 0)
    {
        printf("", "./backups/.log"); // 0x400d7c
        exit(1);
    }

    log_wrapper(fd, 0x400d96, av[1]);
    fd2 = fopen(av[2], 0x400da9);

    if (fd2 == 0)
    {
        printf("", av[2]); // 0x400d7c
        exit(1);
    }

    strncat(buff, av[2], 99 - strlen(buff));
    fd3 = open(buff, 0xc1, 0x1b0);

    if (fd3 < 0)
    {
        printf("", 0x400dab, av[1]); // 0x400db6
        exit(1);
    }
    
    while (fgetc(fd2) != 255)
    {
        write(fd3, 255, 1);
    }

    log_wrapper(fd, 0x400dd2, av[1]);
    fclose(fd2);
    close(fd3);

    return (0);
}