#include <stdio.h>
#include <stdlib.h>
#include "./linked.h"

bool isEmpty(Queue *self){
    return ((ListQueue*)self)->head == NULL;
}
void print(Queue *self){
    ListQueue *q = (ListQueue*)self;
    ListNode *tmp = q->head;
    printf("Here is your list: ");
    while(tmp != NULL){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}
void destroy(Queue *self){free(self);}
Queue* enqueue(Queue *self, int x){
    ListQueue* q = (ListQueue*)self;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = x;
    newNode->next = NULL;
    if(q->head == NULL){
        q->head = newNode;
    }else {
        (*q->pointerToTail)->next = newNode;
        // Why does it not work with &newNode;
        (q->pointerToTail) = &(*q->pointerToTail)->next;
    }
    return self;
}

int dequeue(Queue *self){
    ListQueue* q = (ListQueue*)self;
    if(q->head == NULL){
        printf("empty");
        // TODO
        // Should we throw here ? 
        return -1;
    }else {
        ListNode * temp = q->head;
        ((ListQueue*)self)->head = ((ListQueue*)self)->head->next;

        int returnValue = temp->val;
        free(temp);
        return returnValue;
    }
}

Queue *appendQueue(Queue *self, Queue *oth){   
    if (self->vtable->isEmpty(self)){
        self->vtable->destroy(self);
        return oth;
    }
    else {
        while(!oth->vtable->isEmpty(oth)){
           self->vtable->enqueue(self, oth->vtable->dequeue(oth));                  
        }
    }
    // What is best pratice here ?
    //oth->vtable->destroy(oth);

    return self;
}

QueueInterface listQueueVtable = {
    isEmpty: &isEmpty,
    print: &print,
    destroy: &destroy,
    enqueue: &enqueue,
    dequeue: &dequeue,
    appendQueue: &appendQueue
};

Queue* makeListQueue() {
    ListQueue *q = (ListQueue*)malloc(sizeof(ListQueue));
    q->vtable = &listQueueVtable;
    q->head = NULL;
    q->pointerToTail = &q->head;

    return (Queue*)q;
}

