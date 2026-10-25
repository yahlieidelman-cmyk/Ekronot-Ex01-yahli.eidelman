#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linkedList
{
	unsigned int num;
    struct linkedList *next;
}linkedList;

void initList(linkedList **head);
void addToHead(linkedList **head,unsigned int num); 
int removeFromHead(linkedList **head);
void freeList(linkedList **head);

#endif /* LINKEDLIST_H */