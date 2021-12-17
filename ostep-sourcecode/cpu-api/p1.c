#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("hello world (pid %d)\n", (int)getpid());
    int rc = fork(); // 创建子进程
    if (rc < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello, I'm child (pid %d)\n", (int)getpid());
    } else {
        printf("Hello, I'm parent of %d (pid: %d)\n", rc, (int)getpid());
    }
    return 0;
}