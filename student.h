#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "person.h"
#include "course.h"

class Student:public Person //inherits the parent class                                                                                                             
{                         
  friend class University;
protected:                                                                                           
  long StuId;                                                                                                                                                       
  int yearOfStudy;                                                                                                                                                  
  string major;                                                                                                                                                     
  long advisorId;                                                                                                                                                   
  vector<Course> coursesTaken;                                                                                                                                      
  static long nextStId;  // initialize it to 500                                                                                                                    
 public:                                                                                                                                                            
  Student();                                                                                                                                                        
  Student(int y,string m, long aID,string n, string e, string a, string d, string g);
  void print();                                                                                                                                                     
};

#endif