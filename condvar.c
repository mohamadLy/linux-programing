#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t condvar;

struct queue{
    int c;
    struct queue *next;
}my_queue;
struct queue* head = NULL;
int add(int c ) {
    if (head == NULL) {
        struct queue* my_queue = malloc(sizeof (struct queue));
        my_queue->c= c;
        my_queue->next = NULL;
        head = my_queue;
    } else {
        struct queue* new_node = malloc(sizeof (struct queue));
        new_node->c = c; 
        new_node->next = NULL;
        new_node->next = head;
        head = new_node;
    }
    return 0;
}
char remove_queue() {
    struct queue* tp;
    if (head != NULL) {
        tp = head;
        head = head->next;
        tp->next = NULL;
    }
    return tp->c;
}
void print_queue() {
    struct queue* tp = head;
    while (tp != NULL) {
        printf("%c ", tp->c);
        tp = tp->next;
    }
}

void* function1(void* arg) {
    int counter = 10;
    while (counter > 0) {
        pthread_mutex_lock(&mutex);
        add(counter);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condvar);
        sleep(1);
        counter--;
    }           
}
void* function2( void* arg ) {
    int data = 0;
    while (data != 1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&condvar, &mutex);
        data = remove_queue();
        pthread_mutex_unlock(&mutex);
        printf("data got from queue %d\n", data);
    }
}

int main() {
    printf("Starting main\n");
    pthread_t thread1, thread2;
    char a = 'a';
    pthread_create(&thread1, NULL, &function1, NULL);
    pthread_create(&thread2, NULL, &function2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Ending main\n");
    return 0;
}
