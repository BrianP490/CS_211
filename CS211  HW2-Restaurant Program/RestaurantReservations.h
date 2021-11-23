/*******************
Homework 2 Brian  Perez
This is the header file for Restaurant main where RestaurantReservations class is declared. The private vector of the Restaurant class called restaurants is made. The public functions and the constructors are also included.
*******************/
#ifndef RESTAURANTRESERVATIONS_H
#define RESTAURANTRESERVATIONS_H
#include <vector>
#include <string>
#include "Restaurant.h"
#include "Reservation.h"
using namespace std;

//class declaration
class RestaurantReservations
{
 private:
  vector <Restaurant> restaurants;//list of local restauramts
  
 public:
  //class constructors 
  RestaurantReservations();  
  //class members
  void ProcessTransactionFile(string);  
  void CreateNewRestaurant(string, string, string, string, int);
  void PrintAllRestaurants() const;
  void FindTable(string, string, int, int) const;
  void FindTableAtRestaurant(string, int) const;
  void MakeReservation(string, string, string, int, int);
  void PrintRestaurantReservations(string) const;
};
#endif
