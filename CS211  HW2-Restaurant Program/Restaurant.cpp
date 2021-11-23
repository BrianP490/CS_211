/**************
HW2 Brian Perez
This is the Restaurant implementation file where the member functions and constructors of the Restaurant class are defined.  
******************/
#include <vector>
#include <iomanip>
#include <iostream>
#include "Reservation.h"
#include "Restaurant.h"
using namespace std;
/********************
The overloaded constructor for the restaurant class
The arguments are the passed restaurantName, restaurantAddress, restaurantCity, restaurantType, and the restaurant capacity.
*************/
Restaurant::Restaurant(string rName, string rAddress, string rCity, string rType, int rCapacity)
{
  restaurantName = rName;//store the restaurant name
  restaurantAddress = rAddress;//store the restaurantAddress
  restaurantCity = rCity;//store the restaurant city
  restaurantType = rType;//store the restauranttype
  //sets the entire seat array to the rCapacity
  availableSeats[0] = rCapacity;
  availableSeats[1] = rCapacity;
  availableSeats[2] = rCapacity;
  availableSeats[3] = rCapacity;
}
Restaurant::Restaurant()//default constructor
{
}
/*******************
This function will receive the customer's name, phone number, the group size, and the requested time. Also, it will add the reservation info into the reservations vector while updating the seats available. 
*********************/
void Restaurant::Reserve(string cName, string cPhone, int rGroup, int rTime)
{
  int time;//create a variable to store the time
  time = rTime - 5;//subtract the time by 5 to get the index of the array

  Reservation temp(cName, cPhone, rGroup, rTime);//create a temp reservation class
  reservations.push_back(temp);//add the temp class into the reservations vector

  availableSeats[time] -= rGroup;//update the available seats
}
//prints the private members of the Restaurant class
void Restaurant::printRestInfo() const
{
  cout << left << setw(20) << restaurantName << setw(30) << restaurantCity + ", " + restaurantAddress << left << setw(12) << restaurantType << setw(12) << availableSeats[0] << endl;
}
//returns the name of the Restaurant
string Restaurant::getName() const
{
  return restaurantName;
}
//returns the City of the restaurant
string Restaurant::getCity() const
{
  return restaurantCity;
}
//returns the Type of Restaurant in the private 
string Restaurant::getType() const
{
  return restaurantType;
}
//returns the number of seats available at a time
int Restaurant::getSeats(int time) const
{
  return availableSeats[time - 5];//subtract 5 from the time to get the proper index
}
//this function prints the reservations created in vector
void Restaurant::PrintReservation()const
{
  for(int i = 0; i < reservations.size(); i++)//goes through the reservations vector
    {
      reservations[i].print();//calls the reservation member function
    }
}

