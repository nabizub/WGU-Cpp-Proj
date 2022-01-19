#include <iostream>
#include "Student.h"






    //setters definitions
    void Student::setStudentID(std::string x) { studentID = x;}
    void Student::setFirstName(std::string x) { firstName = x; }
    void Student::setLastName(std::string x) { lastName = x; }
    void Student::setEmail(std::string x) { email = x; }
    void Student::setAge(int x) { age = x; }
    void Student::setDaysInCourse1(int x) { daysArr[0] = x; }
    void Student::setDaysInCourse2(int x) { daysArr[1] = x; }
    void Student::setDaysInCourse3(int x) { daysArr[2] = x; }
    void Student::setDegreeProgram(DegreeProgram x) { degreeProgram = x; }

    //getters definitions
    std::string Student::getStudentID() { return studentID; }
    std::string Student::getFirstName() { return firstName; }
    std::string Student::getLastName() { return lastName; }
    std::string Student::getEmail() { return email; }
    int Student::getAge() { return age; }
    int Student::getDaysInCourse1() { return daysArr[0]; }
    int Student::getDaysInCourse2() { return daysArr[1]; }
    int Student::getDaysInCourse3() { return daysArr[2]; }
    DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

    //Student class constructor definition
    Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
        int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
    {
        setStudentID(studentID);
        setFirstName(firstName);
        setLastName(lastName);
        setEmail(email);
        setAge(age);
        setDaysInCourse1(days1);
        setDaysInCourse2(days2);
        setDaysInCourse3(days3);
        setDegreeProgram(degreeProgram);
    }

    //print() function definition
    void Student::print() {
        //convert degreeProgram to a readable string for output
        std::string program;
        if (degreeProgram == DegreeProgram::NETWORK) { program = "NETWORK"; }
        else if (degreeProgram == DegreeProgram::SECURITY) { program = "SECURITY"; }
        else if (degreeProgram == DegreeProgram::SOFTWARE) { program = "SOFTWARE"; }

        //print
        if (studentID != "removed") {
            std::cout
                << studentID << "   "
                << firstName << "   "
                << lastName << "    "
                << age << "    "
                << "{" << daysArr[0] << ", "
                << daysArr[1] << ", "
                << daysArr[2] << "}"
                << " Degree Program: " << program << std::endl;
        }
        
    }

