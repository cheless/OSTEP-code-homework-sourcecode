#include <stdio.h>
#include <pthread.h>
#include "common_threads.h"

int done = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit() {
    Pthread_mutex_lock(&m);
    done = 1;
    Pthread_cond_signal(&c);    // 发送信号
    Pthread_mutex_unlock(&m);
}

void *chiled(void *arg) {
    printf("child\n");
    thr_exit(); // 唤醒主线程
    return NULL;
}

void thr_join() {
    Pthread_mutex_lock(&m);
    while (done==0) 
        Pthread_cond_wait(&c, &m); // 唤醒后从此处返回
    Pthread_mutex_unlock(&m);
}

int main() {
    printf("parent: begin\n");
    pthread_t p;
    Pthread_create(&p, NULL, chiled, NULL);
    thr_join(); // 将主线程加入等待队列
    printf("parent: end\n");
    return 0;
}