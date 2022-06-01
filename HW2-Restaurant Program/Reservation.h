/************
hw2 Brian Perez
This is the Reservation header file where the Reservation class is declared and the private information is set. The default and overloaded constructores are listed as well as the public member functions.
**************/
#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>

using namespace std;
//create a class called Reservation
class Reservation
{
 private:
  const long reservationNum;//store the reserveNum of the person
  string contactName; //name of the person making reservation
  string contactPhone; //person's phone number
  int groupSize; //number of people in reservation
  int reservationTime;//reservation time 5,6,7, or 8
  static long nextReservationNum;//shared variable for the Reservation class   
 public://constructors
  Reservation();
  Reservation(string, string, int, int);
  //public member function
  void print() const;
  long getResNum() const;
};
#endif
