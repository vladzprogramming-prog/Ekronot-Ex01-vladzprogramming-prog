#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Node structure for the linked list */
struct Node
{
    unsigned int data;
    Node* next;
};

/* LinkedList structure containing a pointer to the head node */
typedef struct LinkedList
{
    Node* head;
} LinkedList;

void initList(LinkedList* list);
void insert(LinkedList* list, unsigned int value); // Always inserts at the head
int removeFirst(LinkedList* list);                 // Always removes from the head
void freeList(LinkedList* list);                   // Cleans up all nodes

#endif // LINKED_LIST_H