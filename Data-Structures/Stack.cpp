#include "Stack.h"
/// NOTE: BASICALLY THE STACK IS THE SAME LINKED LIST, BUT YOU CANNOT ADD OR REMOVE ANYWHERE BUT FROM THE BEGGINING

/// <summary>
/// Inits the stack: (linked list within the Stack's struck
/// </summary>
/// <param name="s">the stack</param>
void initStack(Stack* s)
{
    initList(&(s->list));
}

/// <summary>
/// cleans the stack
/// </summary>
/// <param name="s">the stack</param>
void cleanStack(Stack* s)
{
    freeList(&(s->list));
}

// adds the new element to the stack
void push(Stack* s, unsigned int element)
{
    insert(&(s->list), element);
}


/// <summary>
/// removes the first element from the beggining
/// </summary>
/// <param name="s">the stack</param>
/// <returns>the value popped</returns>
int pop(Stack* s)
{
    return removeFirst(&(s->list));
}


/// <summary>
/// checks if the stack is empty
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool isEmpty(Stack* s)
{
    return s->list.head == nullptr;
}

/// <summary>
/// checks if the stack is full
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool isFull(Stack* s)
{
    return false;
}