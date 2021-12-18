#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rc = fork();
    if(rc < 0)
        printf("failed to fork\n");
    else if (rc == 0) {
        printf("child: (pid: %d)\n", getpid());
        
        // 子进程调用wait啥也没发生，猜测wait是用来wait子进程的，而子进程没有自己的子进程
        wait(NULL); 
    } else {
        int wc = wait(NULL);
        printf("parent: wait num is : %d\n", wc);
    }
}