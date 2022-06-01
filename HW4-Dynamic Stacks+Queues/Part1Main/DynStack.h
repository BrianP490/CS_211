/*************
Brian Perez
CS211
Hw4
--- DynStack.h ---
This is the header file for the dynamic Stack class that declares the private and public function.*************/
#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <string>

using namespace std;
typedef char type;

class Stack
{
 private:
  struct StackNode   //declares the stacknode's info
  {
    type element;   //stores the data
    StackNode* next;   //stores the next node's address using pointers
  };
  
  StackNode* top;  //pointer for the top 

 public:  //pub functions
  Stack();
  ~Stack();
  void destroy();
  void push(type);
  void pop(type&);
  void getTop(type&) const;
  void displayAll() const;
  bool isEmpty() const;
  bool ProperlyBalanced(string);
};
#endif
