/**
 * @file queue.tpp
 * @brief Class template of queue data structure with array implementation
 */

#include<iostream>
#include"queue.h"

/*
*@brief add the data to the queue
*@param the data needed to be added
*/
template<class T>
void Queue<T>::enqueue(int data){
    if (capacity == rear) {
        std::cout<<"\nQueue is full\n";
        return;
    }

    else {
        queue[rear] = data;
        rear++;
    }
    return;
}
/*
*@brief remove the data from th queue
*@param the data needed to be removed
*/
template<class T>
void Queue<T>::dequeue()
{
    // if queue is empty
    if (front == rear) {
        printf("\nQueue is  empty\n");
        return;
    }
    // shift all the elements from index 2 till rear
    // to the left by one
    else {
       for (int i = 0; i < rear - 1; i++) {
           queue[i] = queue[i + 1];
       }

        // decrement rear
        rear--;
    }
    return;
}

/*
*@brief display the queue
*/
template<class T>
void Queue<T>::queueDisplay()
{
   int i;
   if (front == rear) {
       std::cout<<"\nQueue is Empty\n";
       return;
    }

        // traverse front to rear and print elements
        for (i = front; i < rear-1; i++) {
            std::cout<< queue[i]<<" <-- ";
        }
        std::cout<<queue[rear-1];
        return;
    }

template<class T>
void Queue<T>::queueFront()
{
   if (front == rear) {
       std::cout<<"\nQueue is Empty\n";
       return;
   }
    std::cout<<"\nFront Element is: "<< queue[front];
    return;
}
