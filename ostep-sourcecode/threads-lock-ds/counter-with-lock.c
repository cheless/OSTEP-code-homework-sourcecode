#include <stdio.h>
#include <pthread.h>

#include "common_threads.h"

typedef struct counter_t {
    int value;
    pthread_mutex_t lock;
} counter_t;

void counter_init(counter_t *c) {
    c->value = 0;
    Pthread_mutex_init(&c->lock, NULL); // 初始化mutex
}

void increment(counter_t *c) {
    Pthread_mutex_lock(&c->lock);
    c->value++;
    Pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t *c) {
    Pthread_mutex_lock(&c->lock);
    c->value--;
    Pthread_mutex_unlock(&c->lock);
}

int getVal(counter_t *c) {
    return c->value;
}

counter_t c; // 定义一个全局的counter

void *threadIncr(void *arg) {
    int *a = (int*)arg;
    for (int i = 0; i < *a; i++)
        increment(&c);
    return NULL;
}

void *threadDecr(void *arg) {
    int *a = (int*)arg;
    for (int i = 0; i < *a; i++)
        decrement(&c);
    return NULL;
}

int main() {
    counter_init(&c);
    pthread_t p1, p2;
    int times1 = 1000000;
    int times2 = 500000;
    Pthread_create(&p1, NULL, threadIncr, &times1); 
    Pthread_create(&p2, NULL, threadDecr, &times2);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);

    printf("expected value of %d - %d is: %d\n", times1, times2, times1 - times2);
    printf("actual value: %d\n", c.value);
    return 0;
}