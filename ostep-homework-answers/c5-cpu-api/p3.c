#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        printf("child first\n");
    } else {
        sleep(1);
        printf("parent later\n");
    }
}