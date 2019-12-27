//PERSON.CPP

#include "person.h"
#include <iostream>
#include <string>
using namespace std;
Person::Person()
{
  name=email=address=dateOfBirth=gender="UNKNOWN";
}
Person::Person(string n, string e, string a, string d, string g)
{
  name=n;
  email=e;
  address=a;
  dateOfBirth=d;
  gender=g;
}

