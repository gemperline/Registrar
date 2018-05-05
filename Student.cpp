#include "Student.h"

#include <iostream>

Student::Student() {
	numCourses = 0;
	cwid = "";
}

Student::Student(const string &id) {
	cwid = id;
	numCourses = 0;
}

string Student::getCWID() const {
	return cwid; //returns calling object's cwid
}

void Student::addCourseGrade (const string &courseName, char courseGrade) {
	courses[numCourses].courseCode = courseName; //adds new course to the list
	courses[numCourses].grade = courseGrade; // adds the grade for the new course
	numCourses++;
}

double Student::getGPA() {
	double total_grade = 0.0;  //Accumulator used to calculate overall GPA
	
	for (int i = 0; i < numCourses; i++) { //Cycles through each student's grades and treats them to a number to calculate GPA
		if (courses[i].grade == 'A')
			total_grade += 4.0;
		else if (courses[i].grade == 'B')
			total_grade += 3.0;
		else if (courses[i].grade == 'C')
			total_grade += 2.0;
		else if (courses[i].grade == 'D')
			total_grade += 1.0;
		else if (courses[i].grade == 'F')
			continue;
	}
	return (total_grade / numCourses);
}

void Student::printTranscript() { 
	cout << "\n\nTRANSCRIPT FOR CWID: " << cwid << endl;
	for (int i = 0; i < numCourses; i++) {
		cout << courses[i].courseCode << ": " << courses[i].grade << endl; //Cycles through courses and prints CourseName followed by the grade received
	}
	cout << "GPA: " << getGPA() << endl;
}

