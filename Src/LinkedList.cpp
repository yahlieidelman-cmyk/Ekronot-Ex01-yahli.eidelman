#include "LinkedList.h"
#include <iostream>
#define EMPTY -1

void initList(linkedList **head)
{
    *head=NULL;
}
void addToHead(linkedList **head,unsigned int num)
{
    linkedList *newNode=new linkedList();
    newNode->num=num;
    newNode->next=*head;
    *head=newNode;
}
int removeFromHead(linkedList **head)
{
    int num=EMPTY;
    linkedList *temp=NULL;
    if(*head==NULL)
    {
        return EMPTY;
    }
    num=(*head)->num;
    temp=*head;
    *head=(*head)->next;
    delete temp;
    return num;
}
void freeList(linkedList **head)
{
    while(*head!=NULL)
    {
        removeFromHead(head);
    }
}