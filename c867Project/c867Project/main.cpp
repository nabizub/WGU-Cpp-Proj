#include <iostream>
#include <string>
#include "Roster.h"




int main() {
	const std::string studentData[] =
		{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nate,Bizub,nbizub@wgu.edu,23,1,2,3,SOFTWARE" };

	std::cout << "c867 Scripting and Programming - C++ - Student ID:#001423295 - Nate Bizub \n";
	Roster classRoster(studentData);
	classRoster.printInvalidEmails();
	classRoster.printAll();
	classRoster.printAverageDaysInCourse("all");
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
}
// << sizeof(studentData)/sizeof(studentData[0]
/*
* parse studentData > store a
* parse a > store 
* 
* 	Student testStudent("a", "a", "a", "a", 1, 1, 1, 1, SOFTWARE);
	testStudent.print();
*/

