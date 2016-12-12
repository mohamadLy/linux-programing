#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
int main(int argc, const char *argv[])
{
    int fd;
    char buf[13];

    fd = open("myfile.txt", O_CREAT | O_WRONLY, 0600);

    if (fd == 1) {
        printf("Failed to create and open the file. \n");
        exit(1);
    }

    write(fd, "Hello world!", 13);

    close(fd);

    fd = open ("myfile.txt", O_RDONLY);

    if (fd == 1) {
        printf("Failed to create and open the file. \n");
        exit(1);
    }
    
    read(fd, buf, 13);
    buf[13] = '\0';

    printf("%s\n", buf);

    return 0;
}
