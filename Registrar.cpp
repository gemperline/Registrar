#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void Registrar::readTextfile(string filename) 
{
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else{
		throw invalid_argument("Could not open file " + filename);
	}
}

Registrar::Registrar(const Registrar& registrar_obj)
{
	numStudents = registrar_obj.numStudents; //Populating new object with existing object's data...
	students = new Student[50000]; //Allocate space in dynamic memory for the new object's dynamic arrays...

	for (int i = 0; i < numStudents; i++) {  //Copy each element of existing students arrrays to the newly allocated space in dynamic memory to avoid shallow copies
		students[i] = registrar_obj.students[i];
	}
}

Registrar::~Registrar(){ //Destructor deallocates memory associated with the array of students
	delete[] students;
	numStudents = 0;
}


Student& Registrar::getStudent(string cwid) const {

	for (int i = 0; i < numStudents; i++) {
		if (students[i].getCWID() == cwid) { //If supplied CWID is equal to a student's CWID in the list...
			return students[i]; //Return that student
		}
	}
	throw invalid_argument("This CWID is invalid\n"); //If the supplied CWID is not found, throw and exception for invalid CWID
}
Registrar& Registrar::operator=(const Registrar &right)
{
	if (this != &right) {//Check for self assignment

		delete[] students;//Deallocate old memory

		students = new Student[50000]; //Allocate new memory

		numStudents = right.numStudents;

		for (int i = 0; i < numStudents; i++) {
			students[i] = right.students[i];
		}
	}
	return *this;
}
// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) 
{
	for (int i = 0; i < numStudents; i++) {	//Loop through students array to see if the student is already registered.
		if (students[i].getCWID() == cwid) { //If the student is already registered in the student array...
			students[i].addCourseGrade(courseName, grade); //add the new course and grade...
			return;	//go to the next entry.
		}
	} //If we are able to terminate the loop without returning, we can assume that the student is not registered in the student array.
	Student newStudent(cwid); //So create and register the student...
	students[numStudents] = newStudent; 
	students[numStudents].addCourseGrade(courseName, grade); // ...add his course and grade...
	numStudents++; //... and increase the number of students for future loop control.
}

