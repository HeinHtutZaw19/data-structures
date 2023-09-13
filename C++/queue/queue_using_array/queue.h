#ifndef QUEUE_H
#define QUEUE_H

template<class T>

struct Queue {
	int front, rear, capacity;
	T* queue;
	Queue(int c) {
		front = rear = 0;
		capacity = c;
		queue = new T;
	}
	~Queue() { delete[] queue; }

	/*
	*@brief add the data to the queue
	*@param the data needed to be added
	*/
	void enqueue(int data);

	/*
	*@brief remove the data from th queue
	*@param the data needed to be removed
	*/
	void dequeue();

	/*
	*@brief display the queue
	*/
	void queueDisplay();

	/*
	*@brief display the front data of the queue
	*/
	void queueFront();
};
#include "queue.tpp"

#endif
