#include<stdlib.h>

int main() {
    int *x = NULL;
    free(x);
    return 0;
}

// 好像啥也没发生，暂时不知道为啥