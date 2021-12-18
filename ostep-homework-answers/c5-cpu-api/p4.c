#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rc = fork();
    char* args[] = {"ls", "-l", NULL};
    char* env[] = {NULL};
    if(rc < 0)
        printf("failed to fork\n");
    else if (rc == 0) {
        execv("/bin/ls", args);

        // 还有很多变种，作用都一样，掌握一种就行
        // execl("/bin/ls", "ls", "-l", (char *) 0);
        // execle("/bin/ls", "ls", "-l", (char *) 0, env);
        // execve("/bin/ls", args, env);
        // execlp("ls", "ls", "-l", (char *) 0);
        // execvp("ls", args);
    } else {
        sleep(1);
        printf("goodbye\n");
    }
}