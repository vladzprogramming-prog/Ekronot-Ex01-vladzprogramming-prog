#ifndef QUEUE_H
#define QUEUE_H


/* a queue contains positive integer values. */
typedef struct Queue
{
    int* elements;          // Dynamically allocated array
    unsigned int maxSize;   // Maximum capacity
    unsigned int head;      // Index of the front element
    unsigned int tail;      // Index of the next insertion
    unsigned int count;     // Current number of elements
} Queue;

void initQueue(Queue* q, unsigned int size);
void cleanQueue(Queue* q);

void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q); 

bool isEmpty(Queue* s);
bool isFull(Queue* s);

#endif /* QUEUE_H */