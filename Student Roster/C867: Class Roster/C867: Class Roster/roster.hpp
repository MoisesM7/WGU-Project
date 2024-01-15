//
//  roster.hpp
//  C867: Class Roster
//
//  Created by Moises Mercado on 12/2/23.
//
#ifndef roster_hpp
#define roster_hpp
#include "student.hpp"
#include "degree.hpp"
#include <string>


class Roster{
private:
    
   Student* classRosterArray[5];
   int lastIndex;//Index of last student recorded

public:
    Roster();//Constructor
   ~Roster();//Destructor
    
//Accessor to get the lastIndex in the roster
    int getlastIndex() const;
    
//Accessor to get the classRosterArray
    Student* const* getclassRosterArray() const;
   

//Parsing the input student data and adds new student to the roster
void parseAndAddStudent(const std::string& studentData);
    
//Adds new student to the roster with provided details
void add(std::string studentID, std::string& firstName, std::string& lastName, std::string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
//Removes students from roster by Student ID if Student Id does not exist
void remove(std::string StudentID);
    
// Prints Invalid Emails
void printInvalidEmails();
    
//Prints Average Days in course
void printAverageDaysInCourse(std::string studentID);

//Prints DegreeProgram
void printByDegreeProgram(DegreeProgram degreeprogram);
    
//Prints all Students in the roster
void printAll();
    
    

    
};
#endif
