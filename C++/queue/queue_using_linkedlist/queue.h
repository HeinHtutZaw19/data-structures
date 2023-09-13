/**
 *  @file queue.h
 *  @brief Class template of queue implemented by linked list
 */

#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Class template of queue implemented by linked list
 */

template<class T>

class Queue{
    private:
      ///Struct class that implements node for linked list
      struct Node{
            Node *prev,*next;///<previous and next pointers
            T data;///<data that needs to be stored
            Node(T input): data(input), next(nullptr), prev(nullptr){};///<Default constructor
      };

      /// head and tail pointer nodes
      Node *head = nullptr,*tail = nullptr;
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
      void addBefore(T data,T key);
      /**
       * @brief adds the element after the key in the list
       * @param data Element to be inserted
       * @param key Key element before the inserted element
       */
      void addAfter(T data, T key);
    public:
      /**
       * @brief adds the element to the back of the queue
       * @param data Element to be inserted
       */
      void enqueue(T data);
      /**
       * @brief removes the element in the front of the queue
       */
      void dequeue();
      /**
       * @brief prints queue
       */
      void printQueue();

};

#include "queue.tpp"

#endif
