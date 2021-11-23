/**************
HW2 Brian Perez 
This is the Reservation implementation file where all of the Reservation class member functions and constructors are defined. 
**************/
#include <vector>
#include <iostream>
#include <iomanip>
#include "RestaurantReservations.h"
#include "Restaurant.h"
#include "Reservation.h"

using namespace std;

long Reservation::nextReservationNum = 100;//initiolizes the static vatiable
//overloaded constructor initializes the informantion
Reservation::Reservation(string cName, string cPhone, int gSize, int rTime):reservationNum(nextReservationNum)
{
  contactName = cName;//store the cName
  contactPhone = cPhone;//store the cPhone
  groupSize = gSize;//store the group size
  reservationTime = rTime;//store the res time
  nextReservationNum += 10;//update the resNum
}
//default constructor
Reservation::Reservation():reservationNum(nextReservationNum)
{
  contactName = "";//set the cName
  contactPhone = "";//set the cPhone
  groupSize = 0;//set the group size
  reservationTime = 0;//set the res time
  nextReservationNum += 10;//update the resNum
}
//prints all of the private reservation information
void Reservation::print()const
{
  cout << left << setw(20) << reservationNum << setw(20) << contactName << setw(20) << contactPhone << setw(9) << groupSize << reservationTime << ":00 PM" << endl; 
}
//returns the reservation number
long Reservation::getResNum()const
{
  return reservationNum;
}

