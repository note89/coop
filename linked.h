#include "./queue-obj.h"

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