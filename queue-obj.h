#include <stdio.h>
#include <stdbool.h>

typedef struct Queue Queue;
typedef struct QueueInterface QueueInterface;

typedef struct Queue {
    QueueInterface *vtable;
} Queue;

typedef struct QueueInterface {
     bool (*isEmpty)(Queue *self);
     Queue* (*appendQueue)(Queue *self, Queue *oth);
     Queue* (*enqueue)(Queue *self, int x);
     int (*dequeue)(Queue *self);
     void  (*destroy)(Queue *self);
     void  (*print)(Queue *self);

} QueueInterface;