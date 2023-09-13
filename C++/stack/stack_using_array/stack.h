/**
 *  @file stack.h
 *  @brief Class template of stack implemented by linked list
 */

#ifndef STACK_H
#define STACK_H

/**
 * @brief Class template of stack implemented by linked list
 */

template<class T>

class Stack{
    int index=-1;///<current index of the array
    int max_amount=0;///<maximum upper bound of the array
    T* stack_data;///<pointer to stack data
public:

    /*
    *@brief Constructor of stack data strucuture
    */
    Stack(int maximum){
        max_amount= maximum;
        stack_data = new T;
    }
    /*
    *@brief adds the data to the stack
    *@param data needed to be added
    */
    void push(T data);
    /*
    *@brief removes the data from the back
    */
    void pop();
    /*
    *@brief prints the stack
    */
    void printStack();
};

#include "stack.tpp"
#endif
