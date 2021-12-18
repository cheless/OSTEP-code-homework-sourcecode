#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        printf("It's child, the num is: %d\n", num);
        int wc = wait(NULL);
        printf("It's child, the num is: %d\n", num);
    } else {
        printf("It's parent, the num is: %d\n", num);
        int wc = wait(NULL);
        printf("It's parent, the num is: %d\n", num);
        num++;
    }
}