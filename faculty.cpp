#include "faculty.h"

#include <string>
#include <string>
using namespace std;

long Faculty::nextFacultyId=600; 
Faculty::Faculty():Person()
{
  FacId=nextFacultyId++;
  salary=0;
  yearOfExp=0;
  depId=0;
}
Faculty::Faculty( int y, long dId,float sal,string n, string e, string a, string d, string g):Person(n,e,a,d,g)
{
  FacId=nextFacultyId++;
  salary=sal;
  yearOfExp=y;
  depId=dId;
}
void Faculty::print()
{
  cout << "\tFACULTY DETAILS:\n" << "=====================================\n";
  cout << "\tEmail: " << email << endl;
  cout << "\tName: " << name << endl;
  cout << "\tAddress: " << address << endl;
  cout << "\tDate Of Birth: " << dateOfBirth << endl;
  cout << "\tGender: " << gender << endl;
  cout << "\tFaculty ID: " << FacId << endl;
  cout << "\tSalary: " << salary << endl;
  cout << "\tYears Of Experience: " << yearOfExp << endl;
  cout << "\tDepartment ID: " << depId << endl;
}
