//
//  roster.cpp
//  C867: Class Roster
//
//  Created by Moises Mercado on 12/2/23.
//
#include <iostream>
#include <sstream>
#include "roster.hpp"
#include "student.hpp"
#include <string>
 
//Defining Default Consturctor--sets to default Values
Roster::Roster() : lastIndex(-1){
   
}
//Defining non-empty constructor--also allocates appropiate memory for roster size
    Roster::~Roster(){
        for (int i = 0; i <= lastIndex; ++i){
            delete classRosterArray[i];
        }
    }
//Accessor to get the last index in the roster
int Roster::getlastIndex() const {
    return lastIndex;
}

//Accessor to class roster array
Student* const* Roster::getclassRosterArray() const {
    return classRosterArray;
}

//Parsing data and add a new student object to the array
    void Roster::parseAndAddStudent(const std::string& studentData){
        char* data = strdup(studentData.c_str());//Make a copy of the string to use with strtok
        char* token = std::strtok(data,",");
        
        //Parsing and Extracting individual data
        std::string studentID, firstName, lastName, emailAddress;
        int age, daysInCourse1, daysInCourse2, daysInCourse3;
        
        //Parse the comma-seprated values
        studentID = token; token = std::strtok(nullptr, ",");
        firstName = token; token = std::strtok(nullptr, ",");
        lastName = token; token = std::strtok(nullptr, ",");
        emailAddress = token; token = std::strtok(nullptr, ",");
        age = std::stoi(token); token = std::strtok(nullptr, ",");
        daysInCourse1 = std::stoi(token); token = std::strtok(nullptr, ",");
        daysInCourse2 = std::stoi(token); token = std::strtok(nullptr, ",");
        daysInCourse3 = std::stoi(token); token = std::strtok(nullptr, ",");
        
        
        //Parsing DegreeProgram
        DegreeProgram degreeprogram;
            std::string degreeString = token;
            
            if (degreeString == "SECURITY"){
                degreeprogram = SECURITY;
            } else if (degreeString == "NETWORK") {
                degreeprogram = NETWORK;
            } else if (degreeString == "SOFTWARE") {
                degreeprogram = SOFTWARE;
            } else {
                std::cerr << "INVALID!" << std::endl;
                free(data);//free the allocated memory
                return;
            }
    
        //Add a student to the roster
        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
        
        free(data);
    }
//Function to add a new student object to array
void Roster::add(std::string studentID, std::string &firstName, std::string &lastName, std::string &emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
    if(lastIndex < 4 )//Function checks if there is space in the classRosterArray , if it doesnt work Capicity -1 was there.
    {
        lastIndex++;
        classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3,degreeprogram);
    }
}
//Function to remove a student by Student ID
void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--;
            break;
        }
    }
    if (!found) {
        std::cout <<"ERROR! Student with ID " << studentID << " was not found." <<std::endl;
    }
}


//Loop through and print each student with additional info.
void Roster::printAll() {
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->printAll();
    }
}

    
//Function to print Invlaid Emails
void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; ++i) {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos){
            std::cout << "Invalid email: " << email << " StudentID: " << classRosterArray[i]->getStudentID() << std::endl;
        }
    }
}
//Function to print the Average days in course for a specific student
void Roster::printAverageDaysInCourse(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            int* days = classRosterArray[i]->getDaysInCourse();
            double average = static_cast<double>(days[0] + days[1] + days[2]) / 3.0;
            std::cout << "Average days for student " << studentID << ": " << average << std::endl;
            break;
        }
    }
    if (!found){
        std::cout << "ERROR! Student with ID" <<studentID << " was not found." << std::endl;
    }
}

//Function to print by DegreeProgram
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
    for (int i = 0; i <= lastIndex; ++i){
        if ( classRosterArray[i]->getDegreeProgram() == degreeprogram) {
            classRosterArray[i]->printAll();
        }
    }
}

