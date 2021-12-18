#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rc = fork();
    int pid, status;
    if(rc < 0)
        printf("failed to fork\n");
    else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("what happened?\n");
    } else {
        wait(NULL);
        printf("parent: bye\n");
    }
}