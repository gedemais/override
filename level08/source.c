void    log_wrapper(int fd, char *log, char *input) // -0x118(%rbp), -0x120(%rbp),-0x128(%rbp)
{
    char    buff[272];

    strcpy(buff, log);
    snprintf(*buff + strlen(buff), 254 - strlen(buff), input);
    buff[strcspn(buff, "\n")] = 0; // 0x400d4c
    fprintf(fd, "LOG: %s\n", buff); // 0x400d4e

    return (0);
}

int         main(int ac, char **av)
{
    int     fd; // -0x88(%rbp)
    int     fd2; // -0x80(%rbp)
    int     fd3 = -1; // -0x78(%rbp)
    char    tmp;
    char    buff[104] = {0};

    if (ac != 2) // $0x2,-0x94(%rbp)
        printf("Usage: %s filename\n", av[0]); // 0x400d57,  -0xa0(%rbp)
        
    fd = fopen("./backups/.log", 'w'); // 0x400d6d, 0x400d6b

    if (fd == 0)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log"); // 0x400d7c, 0x400d6d
        exit(1);
    }

    log_wrapper(fd, "Starting back up: ", av[1]); // 0x400d96
    fd2 = fopen(av[1], 'r'); // 0x400da9

    if (fd2 == 0)
    {
        printf("ERROR: Failed to open %s\n", av[1]); // 0x400d7c
        exit(1);
    }

    memcpy(buff, "./backups/", 10); // 0x400dab
    strncat(buff, av[1], 99 - strlen(buff));
    fd3 = open(buff, 0xc1, 0x1b0);

    if (fd3 < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]); // 0x400db6, 0x400dab
        exit(1);
    }
    
    while ((tmp = fgetc(fd2)) != 0xff)
        write(fd3, tmp, 1);

    log_wrapper(fd, "Finished back up ", av[1]); // 0x400dd2
    fclose(fd2);
    close(fd3);

    return (0);
}