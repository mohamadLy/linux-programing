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

    key = 3278; // something we made up

    shmid = shmget(key, SHSIZE, IPC_CREAT | 777);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);

     if (shm == (char *)-1) {
            perror("shmat");
            exit(-1);
      }
    char sentence[] = "This would be writen to the shared memory";
    memcpy(shm, sentence, sizeof(sentence));

    while (*shm != '*') {
        sleep(1);
    }

    return 0;
}
