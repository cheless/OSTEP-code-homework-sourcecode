#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common_threads.h"

typedef struct myarg_t {
    int a;
    int b;
} myarg_t;

typedef struct myret_t {
    int a;
    int b;
} myret_t;

void * mythread(void * arg) {
    myarg_t * args = (myarg_t *) arg;
    printf("args: %d, %d\n", args->a, args->b);
    myret_t * rvals = malloc(sizeof(myret_t));
    assert(rvals != NULL);
    rvals->a = 1;
    rvals->b = 2;
    return (void*) rvals;
}

int main() {
    pthread_t p;
    myarg_t args = {10, 20};
    myret_t * rvals;
    Pthread_create(&p, NULL, mythread, &args);
    Pthread_join(p, (void **)&rvals);
    printf("returned: %d, %d\n", rvals->a, rvals->b);
    return 0;
}