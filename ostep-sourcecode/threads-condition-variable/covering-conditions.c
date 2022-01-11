#include <pthread.h>

#include "common_threads.h"

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

const int MAX_HEAP_SIZE = 100;

int bytesLeft = MAX_HEAP_SIZE;

void *allocate(int size) {
    Pthread_mutex_lock(&m);
    while (bytesLeft < size) 
        Pthread_cond_wait(&c, &m);
    void *ptr = ...;    // get member from heap
    bytesLeft -= size;
    Pthread_mutex_unlock(&m);
    return ptr;
}

void free(void *ptr, int size) {
    Pthread_mutex_lock(&m);
    bytesLeft += size;
    pthread_cond_signal(&c);   // whom to signal?? 
    Pthread_mutex_unlock(&m);
}