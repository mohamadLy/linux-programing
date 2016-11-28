#include <stdio.h>
#include <pthread.h>

pthread_t thread1, thread2, thread3;
void *routine(void *);
int main(int argc, const char *argv[])
{
    char *arg1 = argv[1];
    char *arg2 = argv[2];
    char *arg3 = argv[3];

    pthread_create(&thread1, NULL, &routine, arg1);
    pthread_create(&thread2, NULL, &routine, arg2);
    pthread_create(&thread3, NULL, &routine, arg3);

    int i;
//    for (i = 0; i < 3; i++) {
        pthread_join(thread1, NULL);
 //   }
    return 0;
}
