#include <stdio.h>
#include <stdlib.h>
#include "./linked.c"

int main(int argc, char const *argv[])
{
    Queue* mylist = makeListQueue();
    mylist->vtable->enqueue(mylist, 1);
    mylist->vtable->enqueue(mylist, 2);
    mylist->vtable->enqueue(mylist, 3);
    mylist->vtable->enqueue(mylist, 4);
    mylist->vtable->enqueue(mylist, 5);
    
    mylist->vtable->print(mylist);

    printf("%d pop first item \n", mylist->vtable->dequeue(mylist));
    printf("%d pop first item \n", mylist->vtable->dequeue(mylist));
    printf("%d pop first item \n", mylist->vtable->dequeue(mylist));

    mylist->vtable->print(mylist);

    Queue* mylist2 = makeListQueue();
    mylist2->vtable->enqueue(mylist2, 100);
    mylist2->vtable->enqueue(mylist2, 99);
    mylist2->vtable->enqueue(mylist2, 98);

    mylist2->vtable->print(mylist2);

    printf("%d pop first item \n", mylist->vtable->dequeue(mylist2));
    printf("%d pop first item \n", mylist->vtable->dequeue(mylist2));


    mylist2->vtable->print(mylist2);

    printf("Concat the lists\n");

    mylist->vtable->appendQueue(mylist, mylist2);

    mylist->vtable->print(mylist);


    mylist->vtable->destroy(mylist);
    mylist2->vtable->destroy(mylist2);
    return 0;
}
