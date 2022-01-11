typedef struct queue_t{} queue_t;

typedef struct lock_t {
    int flag;
    int guard;
    queue_t *q; // 等待队列
} lock_t;

void lock_init(lock_t *m) {
    m->flag = 0;
    m->guard = 0; // guard保证了每次只有一个线程能进行TestAndSet之后的代码
    queue_init(m->q);
}

void lock(lock_t *m) {
    while(TestAndSet(m->guard, 1) == 1)
        ; // 自旋，等待获取guard锁
    if (m->flag == 0) {
        m->flag = 1;   // 获取临界区锁
        m->guard = 0;  // 释放guard锁后进入临界区
    } else {
        queue_add(m->q, gettid());
        setpark(); // 表示即将进入睡眠，如果发生切换，另一个线程调用unpark()，那么下面的park()将直接返回
        m->guard = 0;
        park(); // 进入休眠，休眠结束即进入临界区
    }
}

void unlock(lock_t *m) {
    while(TestAndSet(m->guard, 1) == 1) 
        ; // 通过自旋获取guard锁
    if (queue_empty(m->q)) 
        m->flag = 0; // 只有等待列表为空才释放锁，其余情况都是将锁“传递”给另外的线程
    else 
        unpark(queue_remove(m->q)); // 让下一个线程获取锁
    m->guard = 0;
}