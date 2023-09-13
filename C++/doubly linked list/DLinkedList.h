/**
 *  @file DLinkedList.h
 *  @brief Class template of doubly linked list implemented
 */

#ifndef DLinkedList_H
#define DLinkedList_H

 /**
  * @brief Class template of doubly linked list implemented by linked list
  */

template<class T>

class DLinkedList {
private:
    ///Struct class that implements node for linked list
    struct Node {
        Node* prev, * next;///<previous and next pointers
        T data;///<data that needs to be stored
        Node(T input) : data(input), next(nullptr), prev(nullptr) {};///<Default constructor
    };

    /// head and tail pointer nodes
    Node* head = nullptr, * tail = nullptr;
public:
    /**
     * @brief adds the element to the front of the list
     * @param data Element to insert
     */
    void pushFront(T data);
    /**
     * @brief removes the element at the front of the list
     */
    void popFront();
    /**
     * @brief returns the element at the front of the list
     */
    T topFront();
    /**
     * @brief adds the element at the back of the list
     */
    void pushBack(T data);
    /**
     * @brief removes the element at the back of the list
     */
    void popBack();
    /**
     * @brief returns the element at the back of the list
     */
    T topBack();
    /**
     * @brief adds the element before the key in the list
     * @param data Element to be inserted
     * @param key Key element after the inserted element
     */
    void addBefore(T data, T key);
    /**
     * @brief adds the element after the key in the list
     * @param data Element to be inserted
     * @param key Key element before the inserted element
     */
    void addAfter(T data, T key);
    /** 
    * @breif print the list
    */
    void printList();
};

#include "DLinkedList.tpp"

#endif
