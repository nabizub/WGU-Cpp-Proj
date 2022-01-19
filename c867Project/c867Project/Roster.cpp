#include <iostream>
#include <string>
#include "Roster.h"



void Roster::parse(const std::string s[]) {
	std::string d = ",";
	for (size_t a = 0; a < 5; a++) // a = "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY" ...
	{
		std::string currStr = s[a];
		std::string store[9] = { "", "", "","", "", "" };
		size_t p = 0;
		std::string t;

		//  split string by "," 
		int count = 0;
		while ((p = currStr.find(d)) != std::string::npos) {
			t = currStr.substr(0, p);
			store[count] = t;
			count++;
			currStr.erase(0, p + d.length());
			if (currStr == "SECURITY" || "NETWORK" || "SOFTWARE") {
				store[8] = currStr;
			}
		}

		// put parsed strings into variables and convert when necessary 
		std::string stdID = store[0];
		std::string fname = store[1];
		std::string lname = store[2];
		std::string ema = store[3];
		// convert string to int
		int intAge = stoi(store[4]);
		int intDays1 = stoi(store[5]);
		int intDays2 = stoi(store[6]);
		int intDays3 = stoi(store[7]);
		// convert string to DegreeProgram
		std::string sdp = store[8];
		DegreeProgram dp = DegreeProgram::SOFTWARE;
		if (sdp == "NETWORK") {
			dp = DegreeProgram::NETWORK;
		}
		else if (sdp == "SECURITY") {
			dp = DegreeProgram::SECURITY;
		}

		// creates and adds parsed students to studentRosterArray
		add(stdID, fname, lname, ema, intAge, intDays1, intDays2, intDays3, dp, a);
	}

}

// constructor
Roster::Roster(const std::string s[]) {
	parse(s);
}

Roster::~Roster() { delete [] studentRosterArray; }


void Roster::add(std::string studentID, std::string firstName,
	std::string lastName, std::string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeprogram, size_t studentNum)
{
		studentRosterArray[studentNum] = new Student(studentID, firstName, lastName, emailAddress,
			age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
		
};

void Roster::remove(std::string studentID) {
	for (size_t i = 0; i < ArrLen; i++)
	{
		std::string currID = studentRosterArray[i]->getStudentID();
		if (currID == studentID) {
			studentRosterArray[i]->setStudentID("removed");
			std::cout << "Student was removed" << std::endl;
			break;
		}else if(currID != studentID && i == 4) { std::cout << "Such a student with this ID was not found." << std::endl; }
		
	};
}

void Roster::printAll() {
	for (size_t i = 0; i < ArrLen; i++)
	{
		studentRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(std::string studentID) {
	float avg = 0.0;
	for (size_t i = 0; i < ArrLen; i++)
	{
		std::string currID = studentRosterArray[i]->getStudentID();
		if (currID == studentID) {
			int day1 = studentRosterArray[i]->getDaysInCourse1();
			int day2 = studentRosterArray[i]->getDaysInCourse2();
			int day3 = studentRosterArray[i]->getDaysInCourse3();

			avg = (day1 + day2 + day3) / 3;
			std::cout << avg << std::endl;
			break;
		}
		else if (studentID == "all") {
			
			int day1 = studentRosterArray[i]->getDaysInCourse1();
			int day2 = studentRosterArray[i]->getDaysInCourse2();
			int day3 = studentRosterArray[i]->getDaysInCourse3();
			avg = (day1 + day2 + day3) / 3;
			std::cout << "ID: " << currID << " Average days in course: " << avg << std::endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (size_t i = 0; i < ArrLen; i++)
	{
		char at = '@';
		char period = '.';
		char space = ' ';
		Student* currS = studentRosterArray[i];
		std::string cEmail = currS->getEmail();
		size_t p = 0;
		if (cEmail.find(at) == std::string::npos || 
			cEmail.find(period) == std::string::npos || 
			cEmail.find(space) != std::string::npos) 
		{
			std::cout << "Invalid email: " << cEmail << "\n" << " -From student account: ";
			currS->print();
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp) {
	for (size_t i = 0; i < ArrLen; i++)
	{
		if (studentRosterArray[i]->getDegreeProgram() == dp) 
		{
			studentRosterArray[i]->print();
		}
	}
}