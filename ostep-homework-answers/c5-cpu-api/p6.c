#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rc = fork();
    int pid, status;
    if(rc < 0)
        printf("failed to fork\n");
    else if (rc == 0) {
        printf("child: (pid: %d)\n", getpid());
    } else {
        int wc = waitpid(rc, &status, WUNTRACED);
        printf("parent: wait num is : %d\n", wc);

        if(WIFEXITED(status))
            printf("normal termination of child (%d), exit status = %d\n", pid, WEXITSTATUS(status));
        printf("Goodbye from parent (%d)\n", getpid());
    }
}