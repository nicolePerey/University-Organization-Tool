 //DEPARTMENT.H
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>
using namespace std;

class Department
{
  friend class University;
protected:
  long DepId;
  string name;
  string location;
  long chairId;
  static long nextDepartId;  // Should be Initialize to 100
public:
  Department();
  Department(string n, string l, long chair);
  void print();
};

#endif
