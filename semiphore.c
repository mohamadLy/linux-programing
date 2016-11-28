#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
void *myfunc1(void *ptr);
void *myfunc2(void *ptr);

int A[100];


int main() {

    printf("Starting program!\n\n\n");
    pthread_t thread1, thread2;
    void **retval;

    char *msg1 = "First thread";
    char* msg2 = "Second thread";

    sem_init(&sem, 0, 1);

    pthread_create(&thread1, NULL, myfunc1, msg1);
    pthread_create(&thread2, NULL, myfunc2, msg2);

    pthread_join(thread1, retval);
    pthread_join(thread2, retval);
    printf("Ending program!\n");

    sem_destroy(&sem);
    return 0;
}

void* myfunc1( void *ptr) {
    char *msg1 = (char*)ptr;
    printf("Thread 1 %s\n", msg1);
    int i;
    for (i = 0; i < 100; i++) {
        printf("X");
        sem_wait(&sem);
       A[i] = i; 
       sem_post(&sem);
    }
}
void* myfunc2( void *ptr) {
    char *msg2 = (char*)ptr;
    printf("Thread 1, %s\n", msg2);
    int i;
    for (i = 0; i < 100; i++) {
        sem_wait(&sem);
        printf("%d ", A[i]);
        sem_post(&sem);
    }
}
