#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main(int argc, const char *argv[])
{
    int shmid;
    key_t key;
    char *shm;

    key = 3278;

    shmid = shmget(key, SHSIZE, 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);

     if (shm == (char *)-1) {
            perror("shmat");
            exit(-1);
      }

    char *s = shm;
    while (*s != 0) {
        printf("%s\n", s);
    }

    *shm = '*';

    return 0;
}
