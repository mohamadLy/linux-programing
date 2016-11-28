#include <stdio.h>
#include <pthread.h>

void *function(void *);
static int counter;
pthread_mutex_t mutex;

int main() {

    pthread_t thread1, thread2;
    int retval = pthread_create(&thread1, NULL, &function, NULL);
    if(retval != 0) {
        printf("Thread creation failed: %d\n", retval);
    }
    retval = pthread_create(&thread2, NULL, &function, NULL);
    if (retval != 0) {
        printf("Thread creation failed: %d\n", retval);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread1, NULL);

    return 0;
}

void *function(void * arg) {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("counter is equal to =%d\n ", counter);
    pthread_mutex_unlock(&mutex);
}
