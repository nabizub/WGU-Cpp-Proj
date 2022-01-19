#pragma once
#include "Student.h"





const int ArrLen = 5;


class Roster
{
	// array of pointers
	Student* studentRosterArray[ArrLen];
	
public:
	// constructor
	Roster(const std::string s[]);

	~Roster();

	// Roster functions
	void parse(const std::string s[]);

	// sets the instance variables from part D1 and updates the roster
	void add(std::string studentID, std::string firstName,
		std::string lastName, std::string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3,
		DegreeProgram degreeprogram, size_t studentNum); 

	// removes students from the roster by student ID
	// If the student ID does not exist,
	// the function prints an error message indicating that the student was not found
	void remove(std::string studentID);

	// prints a complete tab-separated list of student data in the provided format
	// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20  
	// [tab]daysInCourse: {35, 40, 55} Degree Program: Security
	// should loop through all the students in
	// classRosterArray and call the print() function for each student
	void printAll();

	// prints a student’s average number of days in the three courses
	// the student is identified by the studentID parameter
	void printAverageDaysInCourse(std::string studentID);

	// verifies student email addresses and displays all invalid email addresses to the user
	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram dp);
};
	
