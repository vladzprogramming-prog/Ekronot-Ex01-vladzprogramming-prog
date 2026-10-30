#include "Queue.h"
#include <iostream>


/// <summary>
/// This function initialises the queue
/// </summary>
/// <param name="q"> the queue itself</param>
/// <param name="size">the max size of the queue</param>
void initQueue(Queue* q, unsigned int size)
{
    q->elements = new int[size]; // C++ dynamic allocation
    q->maxSize = size;
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}


/// <summary>
///  This function clears the queue
/// </summary>
/// <param name="q">the queue</param>
void cleanQueue(Queue* q)
{
    delete[] q->elements; // Freeing the array memory
    q->elements = nullptr;
    q->maxSize = 0;
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

/// <summary>
/// checks whether the queue is empty
/// </summary>
/// <param name="q">the queue</param>
/// <returns></returns>
bool isEmpty(Queue* q)
{
    return q->count == 0;
}

/// <summary>
/// checks if the queue is yet full
/// </summary>
/// <param name="q">the queue</param>
/// <returns></returns>
bool isFull(Queue* q)
{
    return q->count == q->maxSize;
}


/// <summary>
/// adds an element to the queue, does nothing if the size is already max'ed
/// </summary>
/// <param name="q">the queue</param>
/// <param name="newValue">the value were adding</param>
void enqueue(Queue* q, unsigned int newValue)
{
    if (isFull(q)) {
        return;
    }
    q->elements[q->tail] = newValue; // adds the new value to the tail (the tail is defaulty empty)
    q->tail = (q->tail + 1) % q->maxSize; // Circular array movement: so we shouldn't look at the queue as a pure q->elements list, we should look
    q->count++;                           // at it as a list starting at q->head and ending in q->tail, we do the circular movement
                                          // in order to fill all the space: suppose we have a queue: 1 2 3 4 5, we remove first 2 with dequeue: _ _ 3 4 5, now the enqueue
                                          // adds the next nums IN THE BEGGINING to fill the space: 6 7 3 4 5, BUT THE HEAD STILL IS STUCK AT 3! SO EVEN THOUGH IT "LOOKS" LIKE IT STARTS WITH A 6, THE QUEUE IS ACTUALLY 3 4 5 6 7
}


/// <summary>
/// Pops the first element from the queue
/// </summary>
/// <param name="q"></param>
/// <returns></returns>
int dequeue(Queue* q)
{
    if (isEmpty(q)) {
        return -1;
    }
    int value = q->elements[q->head];
    q->head = (q->head + 1) % q->maxSize; // move the head forward in the circular movement similar to the enqueue logic
    q->count--;
    return value;
}