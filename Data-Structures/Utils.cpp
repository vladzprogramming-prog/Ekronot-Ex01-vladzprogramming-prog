#include "Utils.h"
#include "Stack.h"
#include <iostream>


/// <summary>
/// As needed in the excercise: a function that reverses a list using a Stack
/// </summary>
/// <param name="nums">the list of numbers</param>
/// <param name="size">the size of the array</param>
void reverse(int* nums, unsigned int size)
{
    Stack s; // Init the stack were going to be using
    initStack(&s);

    // Push all elements onto the stack
    for (unsigned int i = 0; i < size; i++) {
        push(&s, nums[i]);
    }

    // Pop them back into the array (LIFO order naturally reverses them)
    for (unsigned int i = 0; i < size; i++) {
        nums[i] = pop(&s);
    }

    cleanStack(&s); // Clean the memory left
}

/// <summary>
/// This function asks the user for 10 numbers using the (std::cin) reverses them using the function and returns the result
/// </summary>
int* reverse10()
{
    const unsigned int SIZE = 10; // Memory allocation for the SIZE const and nums list
    int* nums = new int[SIZE];

    std::cout << "Enter 10 numbers:\n";
    for (unsigned int i = 0; i < SIZE; i++) { // Ask the user for 10 numbers
        std::cin >> nums[i];
    }

    // Reverse them using our reverse function
    reverse(nums, SIZE);

    return nums;
}