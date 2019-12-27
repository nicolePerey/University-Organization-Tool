#include "student.h"
//#include "person.cpp"
#include <iostream>
#include <string>
using namespace std;

long Student::nextStId = 500;
Student::Student():Person()
{
  StuId = nextStId++;
  yearOfStudy=0;
  major="UNKNOWN";
  advisorId=0;
}
Student::Student(int y,string m, long aID,string n, string e, string a, string d, string g):Person(n,e,a,d,g)
{
  StuId = nextStId++;
  yearOfStudy = y;
  major = m;
  advisorId = aID;
}

void Student::print()
{
  cout << "\tSTUDENT DETAILS:\n" << "=====================================\n";
  cout << "\tEmail: " << email << endl;
  cout << "\tName: " << name << endl;
  cout << "\tAddress: " << address << endl;
  cout << "\tDate Of Birth: " << dateOfBirth << endl;
  cout << "\tGender: " << gender << endl;
  cout << "\tStudent ID: " << StuId << endl;
  cout << "\tYear Of Study: " << yearOfStudy<< endl;
  cout << "\tMajor: " << major << endl;
  cout << "\tAdvisor ID: " << advisorId << endl;
}
