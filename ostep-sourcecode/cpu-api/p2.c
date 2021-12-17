#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("hello world (pid %d)\n", (int)getpid());
    int rc = fork(); // 创建子进程
    if (rc < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello, I'm child (pid %d)\n", (int)getpid());
    } else {
        int wc = wait(NULL);
        printf("Hello, I'm parent of %d (wc: %d) (pid: %d)\n", 
            wc, rc, (int)getpid());
    }
    return 0;
}