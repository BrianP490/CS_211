#ifndef STATQUEUE_H
#define STATQUEUE_H
#include <iostream>

using namespace std;

typedef char elm_t;

class Queue
{
    public:
    Queue::Queue();

    bool Queue::isFull() const;


    bool Queue::isEmpty() const;


    void Queue::enqueue(elm_t A);

    void Queue::dequeue(elm_t& A);

    void Queue::displayAll();
};
#endif