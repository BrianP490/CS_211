/******************8
Brian Perez
CS 211
12/4/19
HW4 - Problem 2
--- QueGen.cpp --- 
This program will show all the possible 1-character, 2-character, and 3-character strings that can be formed using the letters A, B, and C.
***********/
#include "DynQue.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  Queue q;     //create a Queue object
  elm_t A = "A", B = "B", C = "C", temp;   //create the variables

  q.enqueue(A);    //add the three strings to the array
  q.enqueue(B);
  q.enqueue(C);

  do{
    q.dequeue(temp);     //get the value from the queue
    cout << temp << endl;    //show the string
    q.enqueue(temp + A);    //add extra letters to the string 
     q.enqueue(temp + B);
     q.enqueue(temp + C);

  }while(temp != "CCC");   //exit the loop when the maximum combinations have been made
}

