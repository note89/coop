#include <stdio.h>
#include <stdbool.h>

typedef struct Queue Queue;
typedef struct QueueInterface QueueInterface;

typedef struct Queue {
    QueueInterface *vtable;
} Queue;

typedef struct QueueInterface {
     bool (*isEmpty)(Queue *self);
     /*
     int dequeue(Queue *self, Queue **ret);
     Queue *appendQueue(Queue *self, Queue *oth);
     */
     Queue* (*enqueue)(Queue *self, int x);
     void  (*destroy)(Queue *self);
     void  (*print)(Queue *self);
} QueueInterface;

/*
struct RingBufferQueue {
     QueueInterface *vtable;
     int *buf;
     int head;
     int tail;
     int size;
};
*/

//struct Queue *makeRingBufferQueue();
typedef struct ListNode ListNode;
typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode;

typedef struct ListQueue {
    QueueInterface *vtable;
    ListNode *head;
    ListNode **pointerToTail;
} ListQueue;

struct Queue *makeListQueue(); 