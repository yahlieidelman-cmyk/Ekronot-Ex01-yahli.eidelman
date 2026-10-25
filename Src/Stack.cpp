#include <iostream>
#include "Stack.h"
#define EMPTY -1

void push(Stack *s,unsigned int element)
{
    if(s!=NULL)
    {
        addToHead(&(s->head),element);
        s->_count++;
    }
}
int pop(Stack *s)
{
    int temp=s->head->num;
    if(s==NULL||s->head==NULL)
    {
        return EMPTY;
    }
    removeFromHead(&(s->head));
    s->_count--;
    return temp;
}
void initStack(Stack *s)
{
    if(s!=NULL)
    {
        s->head=NULL;
        s->_elements=NULL;
        s->_count=0;
    }
}
void cleanStack(Stack *s)
{
    while(s->head!=NULL)
    {
        removeFromHead(&(s->head));
    }
    s->_elements=NULL;
    s->_count=0;
}
bool isEmpty(Stack *s)
{
    if(s==NULL)
    {
        return true;
    }
    return(s->head==NULL);
}
bool isFull(Stack *s)
{
    return false;   
}