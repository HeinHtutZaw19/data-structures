/**
 * @file DLinkedList.tpp
 * @brief Class template of doubly linked list data structure implementation
 */
#include<iostream>
#include"DLinkedList.h"

template<class T>
void DLinkedList<T>::pushFront(T new_data) {
    struct Node* new_node = new Node(new_data);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
        new_node->next->prev = new_node;
    }

}
template<class T>
void DLinkedList<T>::popFront() {
    struct Node* temp = head;
    if (head == nullptr) {
        std::cout << "empty";
        return;
    }
    if (head == tail) { head = nullptr; tail = nullptr; }
    else {
        head = temp->next;
        head->prev = nullptr;
    }
    free(temp);

}
template<class T>
T DLinkedList<T>::topFront() {
    return head->data;
}
template<class T>
void DLinkedList<T>::pushBack(T new_data) {
    struct Node* new_node = new Node(new_data);
    if (tail == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
template<class T>
void DLinkedList<T>::popBack() {
    if (head == nullptr) {
        std::cout << "empty";
        return;
    }
    if (head == tail) { head = nullptr; tail = nullptr; }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
}

template<class T>
T DLinkedList<T>::topBack() {
    return tail->data;
}
template<class T>
void DLinkedList<T>::addBefore(T new_data, T key) {
    struct Node* new_node = new Node(new_data);
    struct Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    new_node->next = temp;
    new_node->prev = temp->prev;
    temp->prev = new_node;
    if (new_node->prev != nullptr) {
        new_node->prev->next = new_node;
    }
    if (head == temp) {
        head = new_node;
    }

}
template<class T>
void DLinkedList<T>::addAfter(T new_data, T key) {
    struct Node* new_node = new Node(new_data);
    struct Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
    if (tail == temp) {
        tail = new_node;
    }

}

template<class T>
void DLinkedList<T>::printList() {
        Node* node = head;
        while (node != NULL)
        {
            std::cout<<" "<<node->data;
            node = node->next;
        }
    
}