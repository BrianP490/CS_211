#include "StatQueue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
  count = 0;
  front = -1;
  rear = -1;
}

bool Queue::isFull() const
{
  if(count == MAX)
    return true;
  else
    return false;
}

bool Queue::isEmpty() const
{
  if(count == 0)
    return true;
  else
    return false;
}


void Queue::enqueue(elm_t A)
{
  if(isFull())
    {
      cout << "Queue is full and cannot enqueue " << A <<  endl;
    }
  else
    {
      rear = (rear +1) % MAX;
      Ar[rear] = A;
      count++;
    }
}

void Queue::dequeue(elm_t& A)
{
  if(isEmpty())
    {
      cout << "Queue is empty and cannot dequeue." << endl;
    }
  else
    {
      front = (front + 1) % MAX;
      A = Ar[front];
      count --;
    }
}

void Queue::displayAll()
{
  int temp = front;
  
  for(int i = 0 ; i< count; i++)
    {
      temp = (temp + 1) % MAX;
      cout << Ar[temp] << endl;
    }
}
