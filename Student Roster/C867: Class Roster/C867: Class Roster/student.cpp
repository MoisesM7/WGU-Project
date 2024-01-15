//
//  student.cpp
//  C867: Class Roster
//
//  Created by Moises Mercado on 12/2/23.
//
#include "student.hpp"
#include "degree.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;

//Default Constructor
Student::Student(){
    this->StudentID = "";
    this->FirstName = "";
    this->LastName = "";
    this->EmailAddress = "";
    this->Age = 0;
    this->DaysInCourse[0] = 0;
    this->DaysInCourse[1] = 0;
    this->DaysInCourse[2] = 0;
    this->DegreeProgram = DegreeProgram::SOFTWARE;
}

//Full Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, enum DegreeProgram degreeprogram)

{
    this->StudentID = studentID;
    this->FirstName = firstName;
    this->LastName = lastName;
    this->EmailAddress = emailAddress;
    this->Age = age;
    this->DaysInCourse[0] = daysInCourse1;
    this->DaysInCourse[1] = daysInCourse2;
    this->DaysInCourse[2] = daysInCourse3;
    this->DegreeProgram = degreeprogram;
}

    
//Defining Accessor(Getter)

std::string Student::getStudentID(){
    return this->StudentID;
}
std::string Student::getFirstName(){
    return this->FirstName;
}
std::string Student::getLastName(){
    return this->LastName;
}
std::string Student::getEmailAddress(){
    return this->EmailAddress;
}
int Student::getAge(){
    return this->Age;
}
int* Student::getDaysInCourse(){
    return this->DaysInCourse;
}
DegreeProgram Student::getDegreeProgram(){
    return this->DegreeProgram;
}


//Defining Mutator(Setter)
void Student::setStudentID(std::string studentID){
    this->StudentID = studentID;
}

void Student::setFirstName(std::string firstName){
    this->FirstName = firstName;
}

void Student::setLastName(std::string lastName){
    this->LastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress){
    this->EmailAddress = emailAddress;
}

void Student::setAge(int age){
    this->Age = age;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3){
    this->DaysInCourse[0] = daysInCourse1;
    this->DaysInCourse[1] = daysInCourse2;
    this->DaysInCourse[2] = daysInCourse3;
}
    
void Student::setDegreeProgram(enum DegreeProgram degreeprogram){
    this->DegreeProgram = degreeprogram;
}


//Display method
void Student::printAll(){
    std::cout << StudentID << "\t";
    
    std::cout << "First Name: " << FirstName  << "\t";
    
    std::cout << "Last Name: " << LastName << "\t";
    
    std::cout << "Email: " << EmailAddress  << "\t";
    
    std::cout << "Age: "<< Age  << "\t";
    
    std::cout << "Days in Course: " << DaysInCourse[0] << ", " << DaysInCourse[1] << ", " << DaysInCourse[2] << ", ";
    
    std::cout << "Degree Program: " << degreeToString(DegreeProgram) << std::endl;
}
    
//Converting DegreeProgram to string for Display
std::string Student::degreeToString(enum DegreeProgram degreeprogram){
    switch (DegreeProgram) {
        case DegreeProgram::SECURITY:
            return "SECURITY";
            break;
            
        case DegreeProgram::NETWORK:
            return "NETWORK";
            break;
            
        case DegreeProgram::SOFTWARE:
            return "SOFTWARE";
            break;
            
            
        default:
            return "SOFTWARE";
            break;
    }
}
                
//Destructor
Student::~Student(){
                }
                    
                
                
        

