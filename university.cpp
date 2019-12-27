#include "university.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool University::failure = false;
bool University::success = true;
//----------------------------------------------------------------------------

University::University()
{

}
//----------------------------------------------------------------------------

University::~University()
{

}

//-----------------------------------------------------------------------------


// CREATING NEW 
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{

  if( (depChairId!=0) && (!FacultyExists(depChairId) ) ) 
    {
      cout << "ERROR! The ID " << depChairId << " does not exist" << endl;
      return failure;
    }
  else 
    {
      Department new_department(depName,depLoc,depChairId);
      Departments.push_back(new_department);
      return success;
    }
}
//----------------------------------------------------------------------------
bool University::FacultyExists(long FacID)
{
  for (int i=0; i<Faculties.size(); i++)
    {
       if (Faculties[i].depId==FacID)
	return success;
    }
   return failure;
}
//----------------------------------------------------------------------------

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,
				  int sYearOfStudy, string sMajor, long sAdvisorId)
{
  if( (sMajor!="0")&& (!sMajorExists(sMajor)))

    {
      cout << "ERROR! Invalid input for major" << endl;
      return failure;
    }
  else if( ( sAdvisorId!=0) &&(!sAdvisorIdExists(sAdvisorId)))
    {
      cout << "ERROR! Invalid input for advisor ID" << endl;
      return failure;
    }
  else 
    {
      Student new_student(sYearOfStudy,sMajor,sAdvisorId,sName,sEmail,sAddress,sDateOfBirth,sGender);
      Students.push_back(new_student);
      return success;
    }
} 
//----------------------------------------------------------------------------

bool University::sMajorExists(string sMajor)
{
  for(int i=0; i<Departments.size(); i++)
    {
      if(Departments[i].name==sMajor)
	return success;
    }
  return failure;
}
//----------------------------------------------------------------------------

 bool University::sAdvisorIdExists(long sAdvId)
{
  for(int i=0; i<Students.size();i++)
    {
      if(Students[i].advisorId==sAdvId)
	return success;
    }
  return failure;
}

//----------------------------------------------------------------------------
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  if( (cTaughtBy!=0) && ( !FacultyExists( cTaughtBy)))
    {
      cout << "Teaher ID " << cTaughtBy << "is invalid" << endl;
      return failure;
    }
  else if(!cDeptIdExists(cDepId)) 
    {
      cout << "ERROR! Department ID does not exist" << endl;
      return failure;
    }
  else 
  {
      Course new_course(cName,cDepId,cTaughtBy,cMaxSeat);
      Courses.push_back(new_course);
      return success;
  }
  }

//----------------------------------------------------------------------------
//FIX
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,  float fSalary, int fYearOfExp, long fDepId)
{
  if (!cDeptIdExists(fDepId))
    {
      cout << "Faculty" << fDepId << " Does not exists" << endl;
	return failure;
    }
  else 
  {
      Faculty new_faculty(fYearOfExp,fDepId,fSalary,fName,fEmail,fAddress,fDateOfBirth,fGender);
      Faculties.push_back(new_faculty);
      return success;
  }
}
//----------------------------------------------------------------------------
bool University::cDeptIdExists(long cDepId)
{
  for (int i=0; i<Departments.size(); i++)
    {
      if(Departments[i].DepId==cDepId)
	return success;
    }
  return failure;
}




//LISTS
//----------------------------------------------------------------------------     
bool University::ListDepartments()
{
  for (int i=0; i<Departments.size(); i++)
    {
      Departments[i].print();
      cout << endl;
    }
  return success;
}

//----------------------------------------------------------------------------     

bool University::ListFaculties()
{

  for (int i=0; i<Faculties.size(); i++)
    {
      Faculties[i].print();
      cout << endl;
    }
  
  return success;
}
//----------------------------------------------------------------------------          

bool::University::ListCourses()
{
  for (int i=0; i<Courses.size(); i++)
    {
      Courses[i].print();
      cout << endl;
    }
  return success;
}

//----------------------------------------------------------------------------          

bool University::ListStudents()
{
  for (int i=0; i<Students.size(); i++)
    {
      Students[i].print();
      cout << endl;
    }
  return success;
}
//----------------------------------------------------------------------------
bool University::ListCoursesTaughtByFaculty(long facultyId)
{

  if (!FacultyExists(facultyId))
    {
      cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
      return failure;
    }
  for(int i = 0; i < Courses.size(); i++)
    {
      if (Courses[i].isTaughtBy == facultyId)
	Courses[i].print();
      cout << endl;
    }
  return success;
}
//----------------------------------------------------------------------------



bool University::ListCoursesTakenByStudent(long studentId)
{
  if (!stuExist(studentId))
    {
      cout << "The student id: " << studentId << " does not exist" << endl << endl;
      return failure;
    }
 for(int i = 0; i < Students.size(); i++)
    {
      if (Students[i].StuId == studentId)
        {
	  for (int j = 0; j < Courses.size(); j++)
            {
	      Students[i].coursesTaken[j].print();
	      cout << endl;
            }
        }
    }

  return success;

}
//----------------------------------------------------------------------------   

bool University::stuExist(long stuId)
{
  for (int i = 0; i < Students.size(); i++)
    {
      if (Students[i].StuId == stuId)
	return success;
    }

  return failure;
}

//----------------------------------------------------------------------------     

bool University::ListFacultiesInDepartment (long departId)
{
  if (!cDeptIdExists(departId))
    {
      cout << "The department id: " << departId << " does not exist" << endl << endl;
      return failure;
    }
  for(int i = 0; i < Faculties.size(); i++)
    {
      if (Faculties[i].depId == departId)
	Faculties[i].print();
      cout << endl;
    }

  return success;
}

//----------------------------------------------------------------------------     

bool University::ListStudentsOfAFaculty(long facultyId)
{
  if (!FacultyExists(facultyId))
    {
      cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
      return failure;
    }
  for(int i = 0; i < Students.size(); i++)
    {
      if (Students[i].advisorId == facultyId)
	Students[i].print();
      cout << endl;
    }
  return success;
}
//----------------------------------------------------------------------------   
bool University::ListCoursesOfADepartment(long deparId)
{
  if (!cDeptIdExists(deparId))
    {
      cout << "The department id: " << deparId << " does not exist" << endl << endl;
      return failure;
    }
  for(int i = 0; i < Courses.size(); i++)
    {
      if (Courses[i].departId == deparId)
	Courses[i].print();
      cout << endl;
    }

  return success;
}
//---------------------------------------------------------------------------- 
bool University::AddACourseForAStudent(long courseId, long stId)
{
  if (!stuExist(stId))
    {
      cout << "The student id: " << stId << " does not exist" << endl << endl;
      return failure;
    }

  if(!CourExist(courseId))
    {
      cout << "The course id: " << courseId << " does not exist" << endl << endl;
      return failure;
    }

  for(int i = 0; i < Students.size(); i++)
    {
      if (Students[i].StuId== stId)
        {
	  if (Courses[i].maxAvaliableSeats == Courses[i].assignedSeats)
            {
	      return failure;
	      cout << "Course with number: " << courseId << " is full" << endl << endl;
            }

	  for(int j = 1; j < Courses.size(); j++)
            {
	      if (Courses[j].CRN == courseId)
                {
		  Students[i].coursesTaken.push_back(Courses[j]);
		  Courses[j].assignedSeats++;
                }
            }
        }
    }

  return success;
}
//----------------------------------------------------------------------------   
bool University::CourExist(long courID)
{
  for (int i = 0; i < Courses.size(); i++)
    {
      if (Courses[i].CRN == courID)
	return success;
    }

  return failure;
}
//----------------------------------------------------------------------------                                                                                             
bool University::AssignDepartmentChair(long facultyId, long departId)
{
  if(!FacultyExists(facultyId))
    {
      cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
      return failure;
    }

  if(!cDeptIdExists(departId))
    {
      cout << "The department id: " << departId << " does not exist" << endl << endl;
      return failure;
    }

  for(int i = 0; i < Departments.size(); i++)
    {
      if (Departments[i].DepId == departId)
        {
	  Departments[i].chairId = facultyId;
	  return success;
        }
    }
}

//----------------------------------------------------------------------------     
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{


  if(!FacultyExists(facultyId))
    {
      cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
      return failure;
    }

  if(!CourExist(courseId))
    {
      cout << "The course id: " << courseId << " does not exist" << endl << endl;
      return failure;
    }

  for(int i = 0; i < Courses.size(); i++)
    {
      if (Courses[i].CRN == courseId)
        {
	  Courses[i].isTaughtBy = facultyId;
	  return success;
        }
    }
}
//----------------------------------------------------------------------------   
bool University::ProcessTransactionFile(string fileName)
{

  string command;
  string w1,w2,w3,w4,w5,w6;
  int num;
  long id;
  long id2;
  float salary;

  cout << "\t=================================\n \tOPENING TRANSACTION FILE. . .\n \t=================================\n";
 
  ifstream fin;  
  fin.open(fileName.data());
  if (!fin)
    {
      cout << "ERROR! File could not be opened";
      return failure;
    }


  fin >> command;
  while(fin)
    {
      if(command== "CreateNewDepartment")
	{
	  fin >> w1 >> w2 >> id;
	  CreateNewDepartment(w1 ,w2,id);
     	}
      if(command=="CreateNewCourse")
	{
	  fin >> w1 >> id >> id2 >> num;
	  CreateNewCourse(w1,id,id2,num);
	}
      if(command=="CreateNewFaculty")
	{
	  fin >> w1 >> w2 >> w3 >> w4 >> w5 >> salary >> num >> id;
	  CreateNewFaculty(w1,w2,w3,w4,w5,salary,num,id);
	}
      if (command=="CreateNewStudent")
	{
	  fin >> w1 >> w2 >> w3 >> w4 >> w5 >> num >> w6 >> id;
	  CreateNewStudent(w1,w2,w3,w4,w5,num,w6,id);
	}
     if (command == "ListDepartments")
       {
	 ListDepartments();
       }
     if(command=="ListFaculties")
       {
	 ListFaculties();
	 }
     if (command == "ListCourses")
       {
	 ListCourses();
       }
    if (command == "ListStudents")
       {
	 ListStudents();
       }
    if (command == "ListFacultiesInDepartment")
      {
	fin >> id;

	ListFacultiesInDepartment(id);
      }
    if (command == "ListStudentsOfAFaculty")
      {
	fin >> id;

	ListStudentsOfAFaculty(id);
      }
      
    if (command == "ListCoursesTaughtByFaculty")
      {
	fin >> id;

	ListCoursesTaughtByFaculty(id);
      }
    if (command == "ListCoursesOfADepartment")
      {
	fin >> id;

	ListCoursesOfADepartment(id);
      }

    if (command == "AddACourseForAStudent")
      {
	fin >> id;
	fin >> id2;

	AddACourseForAStudent(id, id2);
      }
    if (command == "ListCoursesTakenByStudent")
      {
	fin >> id;

	ListCoursesTakenByStudent(id);
      }
    if (command == "AssignDepartmentChair")
      {
	fin >> id;
	fin >> id2;

	AssignDepartmentChair(id, id2);
      }

    if (command == "AssignInstructorToCourse")
      {
	fin >> id;
	fin >> id2;

	AssignInstructorToCourse(id, id2);
	}
     fin >> command;
    }
}
