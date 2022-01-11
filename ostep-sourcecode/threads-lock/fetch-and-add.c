int FetchAndAdd(int *ptr) {
    int old = *ptr;
    *ptr += 1;
    return old;
}

typedef struct lock_t {
    int ticket; // 每个获取到ticket的线程最后肯定会被调度
    int turn;
} lock_t;

void lock_init(lock_t *lock) {
    lock->ticket = 0;
    lock->turn = 0;
}

void lock(lock_t *lock) {
    int myturn = FetchAndAdd(lock->ticket); // 取号
    while(myturn != lock->turn) // 等号
        ; // spin-wait
}

void unlock(lock_t *lock) {
    FetchAndAdd(lock->turn); // 叫下一个号
}