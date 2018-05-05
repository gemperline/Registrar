#pragma once
#include <string>

using namespace std;
struct CourseHist {
	string courseCode;
	char grade;
};

class Student {
public:
	Student(); // default constructor
	Student(const string &); // constructor with parameter
	void addCourseGrade(const string &courseName, char grade); // add course name and grade to student's record
	double getGPA(); // calculate and return GPA
	void printTranscript(); // print transcript - see Student.cpp for the format
	string getCWID() const; // return the CWID of this student
private:
	CourseHist courses[50]; //Stores information a student's courses and the grade they recieved.
	int numCourses;
	string cwid;
};
