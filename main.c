#include <stdio.h>
#include <stdlib.h>
#include "./queue-obj.h"

bool isEmpty(Queue *self){return false;}
void print(Queue *self){
    ListQueue *q = (ListQueue*)self;
    printf("head %d\n", q->head->val);
}
void destroy(Queue *self){free(self);}
Queue* enqueue(Queue *self, int x){
    ListQueue* q = (ListQueue*)self;
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->val = x;
    tmp->next = NULL;
    q->head = tmp;
    return self;
}

QueueInterface listQueueVtable = {
    isEmpty: &isEmpty,
    print: &print,
    destroy: &destroy,
    enqueue: &enqueue
};

Queue* makeListQueue() {
    ListQueue *q = (ListQueue*)malloc(sizeof(ListQueue));
    q->vtable = &listQueueVtable;
    q->head = NULL;
    q->pointerToTail = NULL;

    return (Queue*)q;
}

int main(int argc, char const *argv[])
{
    Queue* mylist = makeListQueue();
    int x = 10;
    mylist->vtable->enqueue(mylist, x);
    mylist->vtable->print(mylist);
    //mylist->vtable->destroy(mylist);
    return 0;
}
