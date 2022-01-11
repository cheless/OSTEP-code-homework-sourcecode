#include <assert.h>
#include <pthread.h>

#include "common_threads.h"

const int MAX = 100;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t fill = PTHREAD_COND_INITIALIZER;

int buffer[MAX];    // buffer has only one num
int count = 0;  // amount of buffer
int produce = 0;
int use = 0;

// producer call
void put(int value) {
    assert(count == 0); // ensure buffer is empty
    buffer[produce] = value;
    produce = (produce + 1) % MAX;
    count++;
}

// consumer call
int get() {
    assert(count == 1);
    int getVal = buffer[use];
    use = (use + 1) % MAX;
    count--;
    return getVal;
}

void *producer(void *arg) {
    for (int i = 0; i < (int)arg; i++) {
        pthread_mutex_lock(&mutex);
        while (count == MAX) 
            Pthread_cond_wait(&empty, &mutex); // this step will unlock
        put(i);
        printf("put: %d\n", i);
        Pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex);
    }
}

void *comsumer(void *arg) {
    for (int i = 0; i < (int)arg; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) 
            Pthread_cond_wait(&fill, &mutex);
        int tmp = get();
        printf("get: %d\n", tmp);
        Pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
}

