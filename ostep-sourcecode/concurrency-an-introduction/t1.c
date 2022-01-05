#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "common_threads.h"

static volatile int counter = 0; // volatile用于修饰该变量可能被改变
const int max = 1e7;

void *mythread(void *arg) {
    printf("%s: begin\n", (char *)arg);
    for (int i = 0; i < max; i++) {
	    counter++; 
    }
    printf("%s: done\n", (char *)arg);
    return NULL;
}
                                                                             
int main() {                    
    pthread_t p1, p2;
    printf("main: begin [counter = %d]\n", counter);
    Pthread_create(&p1, NULL, mythread, "A");
    sleep(1);   // 先让线程A运行完毕，结果就正确了
    Pthread_create(&p2, NULL, mythread, "B");
    Pthread_join(p1, NULL); 
    Pthread_join(p2, NULL); 
    printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max*2);
    return 0;
}
