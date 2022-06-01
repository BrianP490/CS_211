/*******************
Brian Perez
Header file for Restaurant class where a restaurant class is defined and private members listed. The public member functions are listed here as well as the default and overloaded constructor.
********************/
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <string>
#include <vector>
#include "Reservation.h"

using namespace std;

//creating a class called Restaurant
class Restaurant
{
 private:
  string restaurantName; //restaurant name
  string restaurantAddress; //restaurant address
  string restaurantCity; //restaurant city
  string restaurantType; //type of food served
  int availableSeats[4]; //array holding # of available seats at four possible times: 5,6,7, and 8pm
  vector <Reservation> reservations; //list of reservations at this restaurant 

 public:
  Restaurant();  //default constructor
  Restaurant(string, string, string, string, int);//overloaded constructor
  //member functions  
  void printRestInfo() const;
  string getName() const;
  string getCity() const;
  string getType() const;
  int getSeats(int time) const;
  void Reserve(string, string, int, int);
  void PrintReservation() const;
};
#endif
