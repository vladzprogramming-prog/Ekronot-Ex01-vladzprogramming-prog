#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

/* A positive-integer value stack, with no size limit */
typedef struct Stack
{
    LinkedList list; // The stack is based on a Linked List! SO, I used a template LinkedList you could see in the repo
} Stack;

void push(Stack* s, unsigned int element);
int pop(Stack* s);
void initStack(Stack* s);
void cleanStack(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);

#endif // STACK_H