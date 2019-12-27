//COURSE.CPP

#include "course.h"
#include <iostream>
#include <string>

long Course::nextCRN=200;
Course::Course()
{
  CRN=nextCRN++;
  maxAvaliableSeats=0;
  name="UNKNOWN";
  departId=0;
  isTaughtBy=0;
}
Course::Course(string n,long d, long t, int m)
{
  CRN=nextCRN++;
  maxAvaliableSeats=m;
  name=n;
  departId=d;
  isTaughtBy=t;
}
void Course::print()
{
  cout << "\tCOURSE DETAILS:\n" << "=====================================\n";
  cout << "\tCRN: " << CRN << endl;
  cout << "\tMax Avaliable Seats: " << maxAvaliableSeats << endl;
  cout << "\tName: " << name << endl;
  cout << "\tDepartment ID:  " << departId << endl;
  cout << "\tIs Taught By: " << isTaughtBy << endl;

}
