/**
 * @file stack.tpp
 * @brief Class template of dynamically stack data structure with array implementation
 */

#include "stack.h"

template<class T>
void Stack<T>::push(T data){
    if(index>=max_amount-1){
        std::cout<<"\nStack is full\n";
    }
    else{
        index++;
        stack_data[index] = data;
    }
}

template<class T>
void Stack<T>::pop(){
    if(index<0){
        std::cout<<"\nStack is empty\n";
    }
    else{
        T x = stack_data[index];\
        index--;
    }
}

template<class T>
void Stack<T>::printStack(){
    if(index<0){
        std::cout<<"\nStack is empty\n";
    }
    for(int i=0;i<index;i++){
        std::cout<<stack_data[i]<<"<--";
    }
    std::cout<<stack_data[index]<<std::endl;
}
