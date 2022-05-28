/************8
Brian Perez
CS 211
12/4/19
HW 4
--- DynQue.h ---
This is the Queue class header that declares the private variables and public functions.
*******************/
#ifndef DYNQUE_H
#define DYNQUE_H
#include <iostream>
using namespace std;
typedef string elm_t;

class Queue
{
 private:
  struct QueueNode  //set the data for the nodes
  {
    elm_t letter;    //create variable for node 
    QueueNode* next;     //declare a pointer variable
  };
  QueueNode* front;  //create pointer for front of list
  QueueNode* rear;   //create pointer for the end of list
  int count;   //declare the node counter

 public:   //pub member functions
  Queue();
  ~Queue();
  void enqueue(elm_t);
  void dequeue(elm_t&);
  void displayAll() const;
  bool isEmpty() const;
};
#endif
