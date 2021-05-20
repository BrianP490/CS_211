/***********************************
Brian Perez
CS211 HW3
11/19/19

This is the header file for the Lists class that declares all the private data and public member functions for the main to use.
***********************************/
#ifndef LISTS_H
#define LISTS_H
#include "Node.h"
#include <iostream>

using namespace std;

class Lists
{
 private:
  Node* head;//head pointer points to the start of linked list

 public://public data member functions
  Lists();
  ~Lists();
  Lists(const Lists& source);
  void readFromArrays(string nArr[], string pArr [], int size);
  void print(); 
  void printReverse();
  void printReverseRec(Node* Ptr);
  void Reverse();
  Lists& operator=(const Lists& source);
  void insert(string pName, string phone);
  void insertAtPos(string pName, string phone, int pos);
  void searchByName(string pName);
  void updateNumber(string name, string newPhone);
  void destroy();
  void removeRecord(string Name);
};
#endif
