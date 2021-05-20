/**********
Brian Perez
CS211
HW4
--- DynStack.cpp ---
This is the dynamic stack implementation file where the public functions are defined******/
#include "DynStack.h"
#include <iostream>

using namespace std;

Stack::Stack()   //constructor that initializes the top pointer
{
  top = nullptr;
}

Stack::~Stack()  //calls the destroy function to erase the stack
{
  destroy();
}

void Stack::destroy()  //this function will destroy the contents of the stack
{
  StackNode* Ptr = top;  //create a pointer to the top;
  StackNode* nextNode;   //create a temporary pointer

  while(Ptr)  //move through the stack
    {
      nextNode = Ptr -> next;  //save the next node's address 
      delete Ptr;
      Ptr = nextNode;  //update pointer
    }
  top = nullptr;
}
/**This function will add a node to the stack. This function receives data from main to use for the node.**/
void Stack::push(type letter)
{
  StackNode* Node;   // create a pointer for the function
  Node = new StackNode;   //save space for a newnode
  Node -> element = letter;
  Node -> next = top;

  top = Node;
}
//the argument sent will be the variable that stores top's value
void Stack::getTop(type& A) const   //this function will return the top's value
{
  A = top -> element;
}
/**this function will take a node off the stack and return that node's data*/
void Stack::pop(type& A)
{
  StackNode* Ptr = top;//set a pointer to the first node, the one that top is pointing to
  if(top)
    {
      A = top -> element;//send the popped element
      top = Ptr -> next;
      delete Ptr;
    }
  else
    cout << "No element to Popback." << endl;
}
//this function will check if the stack is empty
bool Stack::isEmpty() const
{
  if(top)
    return false;
  else
    return true;
}
/*This function will display the stack from top to bottom*/
void Stack::displayAll() const
{
  if(isEmpty())
    {
      cout << "Linked list is empty." << endl;
    }
  else
    {

      StackNode* Ptr = top;  //create a pointer to the top
      while(Ptr)  //loop through the stack
	{
	  cout << Ptr -> element << endl;
	  Ptr = Ptr -> next;  //update the pointer
	}
    }
}
