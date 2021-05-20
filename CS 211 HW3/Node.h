/******************************
Brian Perez
CS211 HW3
11/19/19

This is the Node class header definition where all the private data is set up and declares the Lists calss a friend.
**************************/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node
{
  friend class Lists;//declare the Lists class a friend

 private:
  string name;//create variable for name
  string phoneNumber;//variable for #
  Node* next;//pointer variable for an @
};
#endif
