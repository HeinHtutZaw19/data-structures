/**
 * @file stack.tpp
 * @brief Class template of dynamically stack data structure with linked list implementation
 */
#include<iostream>
#include"stack.h"

template<class T>
void Stack<T>::pushFront(T new_data){
    struct Node* new_node = new Node(new_data);
    if( head == nullptr ){
        head = new_node;
        tail = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
        new_node->next->prev = new_node;
    }

}
template<class T>
void Stack<T>::popFront(){
    struct Node* temp = head;
    if(head==nullptr){
        std::cout<<"empty";
        return;
    }
    if(head==tail){ head = nullptr; tail = nullptr;}
    else{
        head = temp->next;
        head->prev = nullptr;
    }
    free(temp);

}
template<class T>
T Stack<T>::topFront(){
    return head->data;
}
template<class T>
void Stack<T>::pushBack(T new_data){
    struct Node* new_node = new Node(new_data);
    if(tail == nullptr){
        head = new_node;
        tail = new_node;
    }
    else{
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
template<class T>
void Stack<T>::popBack(){
    if(head == nullptr){
        std::cout<<"empty";
        return;
    }
    if(head == tail){ head = nullptr; tail = nullptr;}
    else{
        tail = tail->prev;
        tail->next = nullptr;
    }
}

template<class T>
T Stack<T>::topBack(){
    return tail->data;
}
template<class T>
void Stack<T>::addBefore(T new_data,T key){
    struct Node *new_node = new Node(new_data);
    struct Node *temp = head;
    while(temp != nullptr && temp->data != key){
        temp = temp->next;
    }
    new_node->next = temp;
    new_node->prev = temp->prev;
    temp->prev = new_node;
    if(new_node->prev != nullptr){
        new_node->prev->next = new_node;
    }
    if(head == temp){
        head = new_node;
    }

}
template<class T>
void Stack<T>::addAfter(T new_data,T key){
    struct Node *new_node = new Node(new_data);
    struct Node *temp = head;
    while(temp != nullptr && temp->data != key){
        temp = temp->next;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
    if(new_node->next != nullptr){
        new_node->next->prev = new_node;
    }
    if(tail == temp){
        tail = new_node;
    }

}

template<class T>
void Stack<T>::push(T data){
    pushFront(data);
}
template<class T>
void Stack<T>::pop(){
    popBack();
}

template<class T>
void Stack<T>::printStack(){
    Node *node = head;
    while (node != NULL){
        std::cout<<node->data<<" ";
        node = node->next;
    }
        std::cout<<std::endl;
}



