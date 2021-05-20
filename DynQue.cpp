#include "DynQue.h"
#include <iostream>

using namespace std;

Queue::Queue()  //constructor that sets the pointer ant counter variables 
{
  front = NULL;
  rear = NULL;
  count = 0;
}
//this function will destroy the linked list 
Queue::~Queue()
{
  QueueNode* Ptr = front;  //set pointer to the front
  QueueNode* NextNode;   //create a pointer for a node
  
  while(Ptr)   //keep erasing the nodes
    {
      NextNode = Ptr -> next;   //save the next node's address
      delete Ptr;  
      Ptr = NextNode;   //move the pointer forward
    }
  front = NULL;
}
//this function checks if the queue is empty. returns true or false
bool Queue::isEmpty() const
{
  if(count == 0)   //if the queue is empty returns true
    return true;
  else 
    return false;
}
//This function will remove a node from the queue and return the removed node's value. The temp variable is sent by reference by the main as an argument.
void Queue::dequeue(elm_t& var)
{
  QueueNode* Ptr = front;   //create a pointer to the front of the queue
  if(isEmpty())
    {
      cout << "Cannot destroy because queue is empty.(Underflow)" << endl;
    }
  else
    {
      var = Ptr -> letter;  //store the node's letter
      front = Ptr -> next;  //move the front forward
      delete Ptr;
      count --;
    }
}
/******
This function will add a node to the queue. The elm_t var will receive an appropriate variable to save into the node***/
void Queue::enqueue(elm_t var)
{
  QueueNode* NewNode;   //create a newnode pointer
  NewNode = new QueueNode;    //save the address of the newnode 
  NewNode -> letter = var;    //assign its data
  NewNode -> next = NULL;
 
    if(isEmpty())
      {
	front = NewNode;   //set front to NewNode
	rear = front;    //do the same to rear
      }  
    else
      {
	rear -> next = NewNode; //add the node at the end of the queue
	rear = rear -> next;  //update rear
      }
    count ++;
}
/*this function will display all the nodes inthe queue and does not change the queue's contents********/
void Queue::displayAll() const
{
  QueueNode* Ptr = front;  //create a pointer that initially points to the front
  while(Ptr) //if there is a node
    {
      cout << Ptr -> letter << endl;
      Ptr = Ptr -> next;  //update the pointer
    }
  cout << endl;
}
