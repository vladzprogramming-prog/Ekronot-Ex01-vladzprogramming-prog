#include "LinkedList.h"
#include <iostream>


/// <summary>
/// inits the list
/// </summary>
/// <param name="list">the linked list</param>
void initList(LinkedList* list)
{
    list->head = nullptr;
}

/// <summary>
/// Inserts the element
/// </summary>
/// <param name="list">the list</param>
/// <param name="value">the value wanted to insert</param>
void insert(LinkedList* list, unsigned int value)
{
    Node* newNode = new Node; // C++ dynamic allocation
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;     // New node becomes the head
}
/// <summary>
/// Removes the FIRST element
/// </summary>
/// <param name="list">list</param>
/// <returns>value of the first element</returns>
int removeFirst(LinkedList* list) /// NOTE: We need this function to remove values from the Stack
{                                 // we do NOT need to remove from any other place but the head, so I didnt include there implementation for deletion in other cases
    if (list->head == nullptr)
    {
        return -1; // List is empty
    }

    Node* temp = list->head;
    int value = temp->data;

    list->head = list->head->next; // Move head to the next node
    delete temp;                   // Free memory using C++ delete

    return value;
}

/// <summary>
/// Frees the list
/// </summary>
/// <param name="list">the list</param>
void freeList(LinkedList* list)
{
    Node* current = list->head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    list->head = nullptr;
}