#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "department.h"
#include "faculty.h"
#include "student.h"
#include "course.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class University
{
protected:
  vector<Department> Departments;
  vector<Student> Students;
  vector<Course> Courses;
  vector<Faculty> Faculties;
  static bool failure;
  static bool success;
public:
  University();
  ~University();

  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,int sYearOfStudy, string sMajor, long sAdvisorId);
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,float fSalary, int fYearOfExp, long fDepId);

  bool FacultyExists(long FacID);
  bool sMajorExists(string sMajor);
  bool sAdvisorIdExists(long sAdvId);
  bool cDeptIdExists(long cDepId);
  bool stuExist(long stuId);
  bool CourExist(long courID);

  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment(long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse(long facultyId, long courseId);

  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();

  bool ProcessTransactionFile(string fileName);
};
#endif