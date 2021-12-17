#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    printf("hello world (pid %d)\n", (int)getpid());
    int rc = fork(); // 创建子进程
    if (rc < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello, I'm child (pid %d)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("wc"); // wc means "world count"
        myargs[1] = strdup("p3.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this should not print out");
    } else {
        printf("Hello, I'm parent of %d (pid: %d)\n", rc, (int)getpid());
    }
    return 0;
}