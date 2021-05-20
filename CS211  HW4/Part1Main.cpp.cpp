/***************
Brian Perez
CS 211        
12/4/19
HW 4 ---Problem 1---

This program will check the delimiters of a string to make sure they are properly balanced
***********/
#include "DynStack.h"
#include <iostream>
#include <string>

using namespace std;

bool ProperlyBalanced(string& A);

int main()
{
  string var;  //create a variable to store the string
  do{
    cout << "Enter a string to check if the delimiters are balanced. " << endl;
    cin >> var;

  }while(!ProperlyBalanced(var)); //call the function
  
  cout << "The delimiters are properly balanced. " << endl;
  
  return 0;
}
/*****************************
This function will determine if the delimiters are properly balaned and will report the equality to the user. This function receives a string from main to use and create a stack from it. This function will use the stack functions to easily compare delimiters.
*********************************/
bool ProperlyBalanced(string& A)
{
  bool balance = true;//create a variable for this boolean function
  char t = '\n';              //create a temp variable to store a value from a stack
  char marker = A[1];          //store the char from the string          
  Stack v;      //create a stack object
  for(int i = 0; i <= A.size() -1; i++)          //check the entire string
    {
      marker = A[i];   //store the char into a temp variable
      
      if(A[i] == ')' || A[i] =='}' || A[i] == ']')    //start checking for equality
	{
	  if(v.isEmpty())    //if the stack is empty and has no match
	    {
	      cout << "Extra Delimiter. Not Balanced. " << endl << endl;
	      balance = false;
	    }
	  
	  else
	    {
	      while(!v.isEmpty() && t != '(' && t != '{' && t != '[')   //loop till delimiter is found or stack is empty
		v.pop(t);
	      if(t != '(' && t != '{' && t != '[' && v.isEmpty())
		{cout << "Extra ending delimiter. Not balanced" << endl << endl;
		  return false;
		}

	      switch(t)    //compare the openning delim to the closing delim
		{
		case('('):
		  if(marker != ')'){
		    cout << "Delimiters are not balanced. Mismatch." << endl << endl; 
		    return false;}
		  break;
		case('{'):
		  if(marker != '}'){
		    cout << "Delimiters are not balanced. Mismatch." << endl << endl;
		    return false;}
		  break;
		case('['):
		  if(marker != ']'){
		    cout << "Delimiters are not balanced. Mismatch." << endl << endl;
		    return false;}
		  break;
		default: cout << endl;
		    }

	      t = '\n';    //reset the temp char variable to use in the loop
	    }
	}
      else   
	v.push(A[i]);     //add the char to the stack
    }
  
  if(!v.isEmpty())   //check for extra openning/closing delimiters
    {
      while(!v.isEmpty())    //loop while the stack is not empty
	{
	  v.pop(t);
	  if(t == '(' || t =='{' || t == '[' || t == ')' || t =='}' || t == ']')  //checks to see if there are extra delemiters
	    {
	      cout << "Extra openning delimiter. Not Equal. "<< endl << endl;
	      balance = false;  //set balanced to false
	    }
	}
    }
  return balance;
}
