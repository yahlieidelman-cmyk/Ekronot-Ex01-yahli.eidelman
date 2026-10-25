#include <iostream>
#include "Queue.h"
#define EMPTY -1

void initQueue(Queue *q,unsigned int size)
{
    q->maxSize=size;
    q->empty=true;
    q->count=0;
    q->elements=new unsigned int[size];
}
void cleanQueue(Queue *q)
{
    delete[] q->elements;
    q->elements=NULL;
    q->empty=true;
    q->count=0;
}
void enqueue(Queue *q,unsigned int newValue)
{
    if(!isFull(q))
    {
        q->elements[q->count]=newValue;
        q->count++;
        q->empty=false;
    }
}
int dequeue(Queue *q)
{
    int i=0;
    int flag=EMPTY;
    if(isEmpty(q))
    {
        return EMPTY;
    }
    flag=(int)q->elements[0];
    for(i=0;i<q->count-1;i++)
    {
        q->elements[i]=q->elements[i+1];
    }
    q->count--;
    if(q->count==0)
    {
        q->empty=true;
    }
    return flag;
}
bool isEmpty(Queue *s)
{
    return(s->count==0);
}
bool isFull(Queue *s)
{
    return(s->count==s->maxSize);
}
