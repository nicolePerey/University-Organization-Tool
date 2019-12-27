//DEPARTMENT.CPP
#include "department.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

long Department::nextDepartId=100;
Department::Department()
{
  DepId=nextDepartId++;
  chairId=0;
  name=location="UNKNOWN";
}
Department::Department(string n, string l, long chair)
{
  name=n;
  location=l;
  chairId=chair;
  DepId=nextDepartId++;
}
void Department::print()
{
  cout << endl << endl;
  cout << "\tDEPARTMENT DETAILS:\n" << "=====================================\n";
  cout << "\tDepartment ID: " << DepId << endl;
  cout << "\tName: " << name << endl;
  cout << "\tLocation: " << location << endl;
  cout << "\tChair ID: " << chairId << endl;
}

