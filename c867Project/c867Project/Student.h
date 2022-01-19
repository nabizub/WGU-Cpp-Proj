#pragma once
#include "degree.h"
#include "Student.h"




class Student
{
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysArr[3];
    DegreeProgram degreeProgram;

public:
    //setters declarations
    void setStudentID(std::string x);
    void setFirstName(std::string x);
    void setLastName(std::string x);
    void setEmail(std::string x);
    void setAge(int x);
    void setDaysInCourse1(int x);
    void setDaysInCourse2(int x);
    void setDaysInCourse3(int x);
    void setDegreeProgram(DegreeProgram x);

    //getters declarations
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    int getAge();
    int getDaysInCourse1();
    int getDaysInCourse2();
    int getDaysInCourse3();
    DegreeProgram getDegreeProgram();

    //Student class constructor declaration
    Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
        int age, int days1, int days2, int days3, DegreeProgram degreeProgram);
   
    //print() function declaration
    void print();
};

