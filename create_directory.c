#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>

int main(int argc, const char *argv[])
{
    DIR *dir;
    struct dirent *sdp;
    dir = opendir(".");
    if (dir == NULL) {
        printf("Error! Unable to open directory.\n");
        exit(1);
    }

    while ((sdp = readdir(dir)) != NULL) {
       printf("%s\n", sdp->d_name);
    }
    return 0;
}
