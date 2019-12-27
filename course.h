//COURSE.h
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course
{
  friend class University;
protected:
  long CRN;
  int maxAvaliableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN; // initialize it to 200
public:
  Course();
  Course(string n,long d, long t, int m);
  void print();
};

#endif