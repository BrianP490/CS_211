/***************************************
Brian Perez 
CS211 HW2
11/22/19

This is where the LinkedL header file is implemented and all the member functions are defined. The constructor and other functions are created in this file.
*****************************************/
#include "Node.h"
#include "LinkedL.h"
#include <iostream>
#include <iomanip>

using namespace std;

Lists::Lists()//default constructor that sets the head to null
{
  head = nullptr;
}

Lists::~Lists()//destructor that calls the destroy function
{
  destroy();
}

/****************************
This function will create a linked list by cobinitng the name data and phone number of two different arrays. In each loop, it will append the new node at the end. It recieves two arrays and an int that tells the for loop the iteration cycles.
********************************/
void Lists::readFromArrays(string A[], string B[], int size)
{
  Node* nodePtr;//create a node pointer
  Node* Newnode;//create a pointer for the new nodes' address
  
  for(int i = 0; i < size; i++)//loop to get all the data
    {
      Newnode = new Node;//create a new node and initialize its data
      Newnode -> name = A[i];
      Newnode -> phoneNumber = B[i];
      Newnode -> next = nullptr;
      
      if(!head)//if the head of the list is null
	{
	  head = Newnode;//point the head to the new node
	  nodePtr = head;//set the node Ptr to point to the newly created node;
	}
      else 
	{
	  nodePtr -> next = Newnode;//set the pointer of the previous node the the newly created one
	  nodePtr = nodePtr -> next;//move the pointer over 1
	}
    }
}
/************************
This is the print function that displays all the members in the linked list
****************************/
void Lists::print()
{
  Node* Ptr = head;//create a pointer variable 
  int i = 1;//number the nodes
  
  cout << "Printing Linked List:" << endl;

  while(Ptr)//while we have a node
    {
      cout << i << ". " << Ptr -> name + ", " << Ptr -> phoneNumber << endl;
      Ptr = Ptr -> next;//update the pointer to the next node
      i++;
    }
  cout << endl;
}
/**************
This function will call the recursive function call to print the linked list
************/
void Lists::printReverse()
{
  printReverseRec(head);//able to use head in function call
  cout << endl;
}

/*****************
This function will recursivly print out the linked list in reverse order
 ***************/
void Lists::printReverseRec(Node* Ptr)
{
  if(!Ptr)//if it reached the end of the list
    {
      return;
    }
  printReverseRec(Ptr -> next);//move on to the next node
  cout << Ptr -> name << ", " << Ptr -> phoneNumber << endl;
}
/****************
This function will reverse the contents of the linked list
*****************/
void Lists::Reverse()
{
  Node* Ptr = head;//declare the pointer variables 
  Node* prev = NULL, *next = NULL; 
  
  while (Ptr != NULL) { 
    next = Ptr -> next;//store next 

    Ptr -> next = prev;//Reverse current node's pointer 
  
    prev = Ptr;//Move pointers ahead. 
    Ptr = next; 
  } 
  head = prev;// flip(head);
}

/********************************
This function creates a node, initializes its data to the values sent as arguments, and inserts it in while keeping the list in alphabetical order.
******************************/
void Lists::insert(string pName, string phone)
{
  Node* Ptr = head;//create pointer for list
  Node* prevPtr = head;//save the previous adress of the node
  Node* newNode;//pointer for the new node

  newNode = new Node;//allocate space for Node and save @
  newNode -> name = pName;//store the data
  newNode -> phoneNumber = phone;
  newNode -> next = nullptr;

  if(!Ptr)//is there are no nodes in the list
    {
      head = newNode;
    }

  else if(head -> name > pName)//if the person's name has smallest ascii value
    {
      newNode -> next = head;//maintains the list
      head  = newNode;
    }

  else
    {
      while(Ptr && Ptr -> name < pName)//goes through the list and compares the values 
	{
	  prevPtr = Ptr;//update the prev pointer
	  Ptr = Ptr -> next;//increment the pointer
	}
      if(!Ptr)//if we reached the end of the list
	{
	  prevPtr -> next = newNode;
	} 
      else//if we need to insert the node within the list
	{
	  newNode -> next = prevPtr -> next;
	  prevPtr -> next = newNode;//point the prev node to the new one
	}
    }
}
/********************************
This function will insert a new node, made from the sent arguments, at a certain position. 1 being the start of the linked list, 2 being the second, and so on. 
******************************/
void Lists::insertAtPos(string pName, string phone, int pos)
{
  int i = 1;//counter
  Node* Ptr = head;//pointer for the list
  Node* NewNode = head;//pointer for the new node
  Node* prevPtr;//pointer that tags begind the Ptr

  NewNode = new Node;
  NewNode -> name = pName;
  NewNode -> phoneNumber = phone;
  NewNode -> next = nullptr;

  if(!head)//if no nodes in the list
    {
      head = NewNode;
    }
  else
    {
      if(pos == 1)
	{
	  NewNode -> next = head;
	  head = NewNode;
	}
      else
	{
	  prevPtr = Ptr;//initialize the prevPointer
	  Ptr = Ptr -> next;//move the pointer over 1
	  i++;
	  
	  while(Ptr)//loop while still in linked list
	    {
	      if(i == pos)//if the position matches the i
		{
		  prevPtr -> next = NewNode;//insert the node
		  NewNode -> next = Ptr;//attatch the rest of the nodes to newnode
		  return;
		}
	      prevPtr = Ptr;//set previous pointer to current pointer
	      Ptr = Ptr -> next;//move the pointer to the next node
	      i++;//inclrement the counter
	    }
	  prevPtr -> next = NewNode;//append the new node to the end of the list
	}      
    }
}
/*****************************
This function receives a person's first name to search for in the linked list and the function checks if they are on the list.
**********************************/
void Lists::searchByName(string pName)
{
  Node* Ptr = head;//set a pointer for the list
  int i = 1;//create a tally
  
  while(Ptr)//while there are still nodes
    {
      if(Ptr -> name == pName)//if we found a match
	{
	  cout << pName << " was found in Node: " << i << endl; 
	  return;
	}
      Ptr = Ptr -> next;//move the pointer to the next node
      i++;
    }
  //error message if person was not found on the list
  cout << "Error, no record was found for: " << pName << endl;
}

/***********************
This function will update the person's phone numbr that was sent as an argument
********************/
void Lists::updateNumber(string pName, string phone)
{
  Node* Ptr = head;//create a pointer variable 

  while(Ptr)//while there are still nodes
    {
      if(Ptr -> name == pName)//if we found the person
	{
	  Ptr -> phoneNumber = phone;//change their phone #
	  cout << pName << "'s number was changed." << endl;
	  return;
	}
      Ptr = Ptr -> next;
    }
  //error message
  cout << "Error, no record was found for: " << pName << endl;
}

/*************************
This function will destroy the linked list from the head and finally set the head to null.
 ***********************/
void Lists::destroy()
{
  Node* nodePtr;//set a node pointer
  Node* nextNode;//create a variable for nextNode 

  nodePtr = head;//set the pointer that points to the start of list

  while(nodePtr)
    {
      nextNode = nodePtr -> next;//save the next address int nextNode
      delete nodePtr;//delete the node
      nodePtr = nextNode;//set the nodePtr to the nextNode
    }
  head = NULL;//erase the head
}
/******************
This function will go through the linked list and seek the requested name that was sent as an argument. If the person was found, they will get deletd from the list.
******************/
void Lists::removeRecord(string pName)
{
  Node* nodePtr = head;//set the pointer variable
  Node* prevNode = head;
  bool found = false;//create a variable for found

  while(nodePtr)//while there is an address
    {
      if(nodePtr -> name == pName)//if the person was found
	{
	  if(nodePtr == head && nodePtr -> next)//if the first node is the one
	    {
	      head = nodePtr -> next;
	      delete nodePtr;//delete the node including its data
	      found = true;
	    }
	  else if(nodePtr -> next)//if there are nodes after the current one
	    {
	      prevNode -> next = nodePtr -> next;//connect the surrounding nodes
	      delete nodePtr;
	      found = true;
	    }
	  else if(nodePtr -> next == NULL)//if it is the last node
	    {
	      delete nodePtr;
	      prevNode -> next = nullptr;//set the prev node pointer = to null
	      nodePtr = prevNode;//move back a node
	      found = true;	      
	      }
	}
      prevNode = nodePtr;//move the pointers up a node
      nodePtr = nodePtr -> next;
    }
  //error message or success
  if(!found)
    cout << pName << " was not found for deletion." << endl;
  else
    cout << pName << " was deleted from list." << endl;
}
/*******************
This function will recieve a linked list and perform a deep copy. The copy will be sent back to the main.
*****************/
Lists::Lists(const Lists& source)
{
  Node* nodePtr = source.head;//create a pointer for the copying

  while(nodePtr)
    {
      insert(nodePtr -> name, nodePtr -> phoneNumber);//add the node the the copy
      nodePtr = nodePtr -> next;//point to the next node in the source
    }
}

Lists& Lists::operator=(const Lists& source)
{
  Node* nodePtr = source.head;//create a pointer for the copying
  Node* Ptr = head;
  if(head)//use the delete function on the calling obj 
    {
      while(Ptr)//while there are nodes
	{
	  Ptr = Ptr -> next;
	  delete Ptr;
	}
      head = NULL;
    }
  while(nodePtr)
    {
      insert(nodePtr -> name, nodePtr -> phoneNumber);//add the node the the copy
      nodePtr = nodePtr -> next;//point to the next node in the source
    }
}
