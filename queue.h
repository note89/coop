Queue *makeEmpty();
bool isEmpty(Queue *self); // don't implement this

// Only one of the next two
Queue *enqueue(Queue *self, int x);
int dequeue(Queue *self, Queue **ret);

Queue *appendQueue(Queue *self, Queue *oth); 

