#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
using namespace std;

class Person //super class(parent class) of student and faculty
{
  friend class University;
 protected:
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;
 public:
  Person();
  Person(string n, string e, string a, string d, string g);
  void print();
};

#endif