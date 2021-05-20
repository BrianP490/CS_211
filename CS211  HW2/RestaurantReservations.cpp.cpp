/***************
HW2 Brian Perez
This is the RestaurantReservations implementaion file of the RestaurantReservations class where the functions are defined. Also, the constructors are shown.
***************/
#include <iostream>
#include <fstream>
#include "RestaurantReservations.h"
#include "Restaurant.h"
#include "Reservation.h"
#include <string> 
#include <iomanip>

using namespace std;
//this is the default constructor
RestaurantReservations::RestaurantReservations()
{
}

/***************
This function will process the transaction file, read the instructions, and execute the functions. The parameter that is sent to the function is the file name.
****************/
void RestaurantReservations::ProcessTransactionFile(string File)
{
  ifstream fin;//create an input file stream
  string command;//store the command word
  string rName, rAddress, rCity, rType , cName, cPhone;//store the variables of the restaurant details and the customer's details
  int rCapacity, rGroup, rTime;//store the restaurant seating, group size, and time

  fin.open(File.c_str());//open the text file
  if(!fin)//if file could not be opened
    {
      cout << "Error. File could not be opened." << endl;
    }
  else
    {
      fin >> command;//read the command
      while(fin)//while there is an input, check the command and perform the command
	{
	  if(command == "CreateNewRestaurant")
	    {
	      fin >> rName >> rAddress >> rCity >> rType >> rCapacity;//read more data and enter the function
	      CreateNewRestaurant(rName, rAddress, rCity, rType, rCapacity);
	    }//create a new restaurant with the data     
	  else if(command == "PrintAllRestaurants")//display the results
	    {
	      cout << "\nPrintAllRestaurants:" << endl;
	      cout << left << setw(20) << "Restaurant" << setw(30) << "City, Address" << left << setw(12) << "Type" << setw(12) << "Capacity" << endl << "-------------------------------------------------------------------------" << endl;
	      PrintAllRestaurants();//call the PrintAllRestaurants function
	    }	  
	  else if(command == "FindTable")
	    {
	      fin >> rCity >> rType >> rGroup >> rTime;//read more data and enter the function
	      cout << "\nFind Table " << rCity << " " << rType << " " << rGroup << " " << rTime << endl;
	      FindTable(rCity, rType, rGroup, rTime);//call the FindTable function
	    }	    
	  else if(command == "MakeReservation")
	    {
	      fin >> rName >> cName >> cPhone >> rGroup >> rTime;//reads more data and enter the function
	      MakeReservation(rName, cName, cPhone, rGroup, rTime);//call the function
	    }
	  else if(command == "FindTableAtRestaurant")
            {
	      fin >> rName >> rGroup;//read more data and enter the function
	      cout << "\nFind Table at Restaurant " << rName << " for " << rGroup << ":" << endl;
	      FindTableAtRestaurant(rName, rGroup);//call the member function
            }
	  else if(command == "PrintRestaurantReservations")
	    {
	      fin >> rName;//read the name data and enter the function
	      cout << "\nPrinting Restaurant Reservations for: " << rName << endl;	  
	      PrintRestaurantReservations(rName);//call the member function
	    }
	  fin >> command;//read the next command from the file
	}
      fin.close(); //close the input file
    }  
}
/******************
This function will get the restaurant's information from the arguments passed and create a restaurant class instance. It will also add the newly created class into the restaurants vector. The passed parameters are the restaurant's name, the address, the city, the type of food, and the max capacity.
****************/
void RestaurantReservations::CreateNewRestaurant(string rName, string rAddress, string rCity, string rType, int rCapacity)
{
  Restaurant temp(rName, rAddress, rCity, rType, rCapacity);//call the overload constructor
  restaurants.push_back(temp);//add temp to the restaurants vector
}
/***********
This functon will print out the restaurants in the restaurants vector using a for loop and a member function from the restaurants class.
*************/
void RestaurantReservations::PrintAllRestaurants() const
{
  for(int i = 0; i < restaurants.size(); i++)//loops until all restaurants have been shown
    {
      restaurants[i].printRestInfo();//call the printRestInfo function
    }
}
/**********************
This function will check if there are available seats at a certain restaurant.
The passed parameters are the restaurant's city, the type of food, the group size and the requested time.
*********************/
void RestaurantReservations::FindTable(string rCity, string rType, int rGroup, int rTime) const
{
  bool found = false;//store a boolean variable
  for(int i = 0; i < restaurants.size(); i++)//go through the restaurants vector
    {
      if(restaurants[i].getCity() == rCity && restaurants[i].getType() == rType && rGroup <= restaurants[i].getSeats(rTime))
	{//if we have a match on city, type, and available seats, then it prints the restaurant's name
	  found = true;//change the found to be true
	  cout << restaurants[i].getName() << endl;
	}       	      
    }  
  if(!found)//if it did not find an available location it prints the error message
    {
      cout << "No restaurant can accommodate such a group at this time, check another time." << endl;
    }
}
/*********************
This function recieves the restaurant name, the customer's name, pnone #, group size, and requested time. This function will create the reservation at the restaurant and call the restaurant member function.
********************/
void RestaurantReservations::MakeReservation(string rName, string cName, string cPhone, int rGroup, int rTime) 
{
  for(int i = 0; i < restaurants.size(); i++)//goes throught the restaurant vector
    { 
      if(restaurants[i].getName() == rName)//if the restaurant is found in the vector
	{
	  restaurants[i].Reserve(cName, cPhone, rGroup, rTime);//calls the restaurant reserve function
	}
    }
}
/***************************
This function recieves the restaurant Name and group Size as parameters. This function will search throught the vector of restaurants and if a match was found, it enters another loop. The other loop searches through the times to check if the group size is smaller than or equal to the remaining seats at that time and pushes the available time into a vector.
**************************/
void RestaurantReservations::FindTableAtRestaurant(string Name, int Size)const
{
  bool found = false;
  vector<int> AvailTime;//a vector that saves the available times
  for(int i = 0; i < restaurants.size(); i++)//goes throught the restaurant vector
    {
      if(restaurants[i].getName() == Name)//if the passed Name matches a restaurant name
	{
	  for(int k = 5; k < 9; k++)//since getSeats needs a time between 5 and 9 k must search between 5 and 9
	    {
	      if(restaurants[i].getSeats(k) >= Size)//if there is space save the time in vector AvailTime
		{
		  found = true;//change found to true
		  AvailTime.push_back(k);//add k into the Availtime vector
		}
	    }
	}
    }
  if(found)//print the available times 
    {
      cout << "You can reserve a table for " << Size << " at " << Name << " at ";
      for(int j = 0; j < AvailTime.size(); j++)//go throught the vector of the available times and print the times
	{
	  cout << AvailTime[j] << ":00 pm ";
	}
      cout << " " << endl;
    }   
  if(!found)//print an error message if it did not find a table
    {
      cout << Name << " does not have such availability." << endl;
    }
}
 
/*******************
This function will recieve the restaurant name as a parameter. It will call the PrintReservation function from Restaurant.cpp if the restaurant exists and print the reservations for the restaurant.
**********************/ 
void RestaurantReservations::PrintRestaurantReservations(string Name) const
{
  bool found = false;//create a boolean variable found 

  for(int i = 0; i < restaurants.size(); i++)//search through the restaurant vector 
    {
      if(restaurants[i].getName() == Name)//if it finds the restaurant in the vector
	{//print the information and set found to true
	  found = true;
	  cout << left << setw(20) << "Reservation" << setw(20) << "Contact" << setw(20) << "Phone" << setw(9) << "Group" << "Time" << endl << "-----------------------------------------------------------------------------" << endl; 
	  restaurants[i].PrintReservation();//call the PrintReservation function
	}      
    }
  if(!found)//if it did not find the restaurant print error
    {
      cout << "There are no restaurant reservations for the restaurant." << endl;
    }
}

