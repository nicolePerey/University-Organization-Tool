#ifndef FACULTY_H
#define FACULTY _H

#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Faculty:public Person //inherits the parent class
{
  friend class University;
protected:
  long FacId; 
  float salary;
  int yearOfExp;
  long depId;
  static long nextFacultyId; // initialize it to 600
public:
  Faculty();
  Faculty(int y, long dId,float sal,string n, string e, string a, string d, string g);
  void print();
}; 
#endif