/*****************
Brian Perez
CS211 HW3
11/19/19

This program will test the different functions that can be used on linked lists. Some of the functions include: insert, readFromArrays, print, reverse, updateNumber, and reversePrint.
*****************/
#include "LinkedL.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 3;//create a constant size

int main()
{
  string nameArray [SIZE] = {"Jim Meyer", "Joe Didier", "Mayssaa Najjar"}; 
  string phoneArray [SIZE] = {"337-465-2345", "352-654-1983", "878-635-1234"};
  
  Lists list1;

  // reading from arrays into list 1
  cout << "------------------------------------------" << endl;
  cout << "Reading from arrays into list and printing list1"  << endl;
  list1.readFromArrays(nameArray, phoneArray, SIZE);
  list1.print();

  // adding elements to list1 using insert and insertAtPos 
  cout << "------------------------------------------" << endl; 
  cout << "Adding records to list1 and printing list1" << endl;  
  list1.insert("Henry Hatch", "617-227-5452");
  list1.insert("Kevin Etheredge", "617-437-5454");
  list1.insert("Xavier Perez", "352-654-1983");  
  list1.insertAtPos("Adam James", "202-872-1010", 1);
  list1.insertAtPos("Peter Anderson", "352-654-2000", 7);
  list1.insertAtPos("Jamie Roberts", "202-832-1560", 3);
  list1.insertAtPos("Nancy Garcia", "617-227-5454", 8);
  list1.insertAtPos("Yara Mendiola", "667-277-1454", 11);
  list1.print();
  
  // printing list1 in reverse order 
  cout << "------------------------------------------" << endl;
  cout << "Printing list1 backwards" << endl;
  list1.printReverse();
  
  // searching for specific entries in list1 
  cout << "------------------------------------------" << endl;
  cout << "Searching for specific people in list1" << endl;
  list1.searchByName("Nancy Garcia");   
  list1.searchByName("Kevin Etheredge");
  list1.searchByName("Jamie Roberts");
  list1.searchByName("Julia Sarkis");
  
  // updating specific entries in list1
  cout << "------------------------------------------" << endl;
  cout << "Updating records in list1 and printing list" << endl;
  list1.updateNumber("Peter Anderson", "989-876-1234");
  list1.updateNumber("Nancy Garcia", "345-467-1234");
  list1.updateNumber("Jamie Roberts", "202-447-1234");
  list1.updateNumber("Jamie Garcia", "345-467-1224"); 
  cout << "------------------------------------------" << endl;
  list1.print(); 
 
  // creating another list list2 and adding some elements to it 
  cout << "------------------------------------------" << endl; 
  cout << "Adding nodes to list2 and printing list 2" << endl; 
  Lists list2; 
 
  list2.insertAtPos("Mary Mitchell", "617-227-5454", 1);
  list2.insert("Adam Sage", "202-857-1510");
  list2.print(); 
  
  // calling operator = to modify list2 so it is a copy of list1 
  list2 = list1;
  // creating another list list3 using copy constructor 
  Lists list3(list1);

  // modifying list1 by removing some elements of list1
  list1.removeRecord("Mayssaa Najjar");
  list1.removeRecord("Adam James");
  list1.removeRecord("Yara Mendiola");
  list1.removeRecord("Jamie Najjar");
  
  // printing list1, list2, and list3 to make sure that a deep copy is performed
  cout << "------------------------------------------" << endl;
  cout << "Printing list1 after removing some records" << endl;
  list1.print(); 

  // printing list1, list2, and list3 to make sure that a deep copy is performed  
  cout << "------------------------------------------" << endl; 
  cout << "Printing list2 after calling operator=" << endl; 
  list2.print(); 
  
  cout << "------------------------------------------" << endl;
  cout << "Printing list2 after calling operator=" << endl;
  list2.print(); 
  
  cout << "------------------------------------------" << endl;
  cout << "Printing list3" << endl; 
  list3.print(); 
 
  // reversing the nodes in list3 
  cout << "------------------------------------------" << endl;
  cout << "Printing list3 after reversing it" << endl;
  list3.Reverse(); 
  list3.print(); 
  
  // searching for a specific person in list3
  cout << "------------------------------------------" << endl;
  cout << "Searching for specific person in list3" << endl;
  list3.searchByName("Jamie Roberts"); 
  return 0;
}
