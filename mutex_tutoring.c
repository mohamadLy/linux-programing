#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *myfunc1(void *ptr);
void *myfunc2(void *ptr);

int A[100];

pthread_mutex_t lock;

int main() {

    printf("Starting program!\n\n\n");
    pthread_t thread1, thread2;
    void **retval;

    char *msg1 = "First thread";
    char* msg2 = "Second thread";

    pthread_create(&thread1, NULL, myfunc1, msg1);
    pthread_create(&thread2, NULL, myfunc2, msg2);

    pthread_join(thread1, retval);
    pthread_join(thread2, retval);
    printf("Ending program!\n");
    return 0;
}

void* myfunc1( void *ptr) {
    char *msg1 = (char*)ptr;
    printf("Thread 1 %s\n", msg1);
    int i;
    pthread_mutex_lock(&lock);
    for (i = 0; i < 100; i++) {
        printf("X");
       A[i] = i; 
    }
    pthread_mutex_unlock(&lock);
}
void* myfunc2( void *ptr) {
    char *msg2 = (char*)ptr;
    printf("Thread 1, %s\n", msg2);
    int i;
    pthread_mutex_lock(&lock);
    for (i = 0; i < 100; i++) {
        printf("%d ", A[i]);
    }
    pthread_mutex_unlock(&lock);
}
