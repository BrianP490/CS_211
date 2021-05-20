/**********************
Hw2 Brian Perez 10/11/19
In this program, it will create dinner reservations at local restaurants. The program will create a RestaurantReservations class and call the function ProcessTransactionFile. The ProcessTransactionFile will read commands and other processing information. The commands will call functions that will either create a new restaurant, print all the restaurants, find an available table, find an available table at a certain restaurant, make a reservation at a restaurant, or print the reservations of a restaurant. 
*********************/
#include "RestaurantReservations.h"
#include "Restaurant.h"
#include "Reservation.h"
#include <iostream>
using namespace std;

int main()
{
  RestaurantReservations openTable;//create a restaurantreservation class
  openTable.ProcessTransactionFile("TransactionFile.txt");//call the function
  return 0;
}
