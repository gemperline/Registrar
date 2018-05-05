#pragma once
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;

class Registrar {
public:
	Registrar() { numEntries = 0, numStudents = 0, students = new Student[50000]; }
	Registrar(const Registrar&);
	~Registrar();
	Registrar& operator=(const Registrar &registrarOBJ);
	void readTextfile(string filename); // Load information from a text file with the given filename: THIS IS COMPLETE
	void addLine(string courseName, string cwid, char grade); // process a line from the text file
	Student& getStudent(string cwid) const; // return the Student object corresponding to a given CWID
	

private:
	Student* students; 
	int numEntries, numStudents;

};
