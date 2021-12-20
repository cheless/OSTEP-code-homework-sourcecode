#include <sys/time.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct timeval time_before, time_after; // 定义两个时间结构
    // suseconds_t time_sum;
    int loops = 10000;
    int fd = open("./data.input", O_RDONLY);
    gettimeofday(&time_before, NULL);

    for (int i = 0; i < loops; i++) {
        read(fd, NULL, 0);
    }
    gettimeofday(&time_after, NULL);
    close(fd);

    printf("The averange time of system call \"read\" is: %f microseconds\n", 
            (1000000 * time_after.tv_sec + time_after.tv_usec - 
                1000000 * time_before.tv_sec - time_before.tv_usec) / (float)loops);
}