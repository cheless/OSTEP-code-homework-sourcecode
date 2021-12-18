#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd = open("p2.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        char* s = "Information from child...";
        write(fd, s, strlen(s));
    } else {
        char* s = "Information from parent...\n";
        write(fd, s, strlen(s));
        wait(NULL); // 让子进程先结束以确保文件描述符关闭
        close(fd);
    }
}