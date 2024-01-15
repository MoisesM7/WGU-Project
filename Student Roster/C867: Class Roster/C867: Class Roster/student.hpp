//
//  student.hpp
//  C867: Class Roster
//
//  Created by Moises Mercado on 12/2/23.
//
#include "degree.hpp"
#include <iostream>
#include <string>
#ifndef student_hpp
#define student_hpp
 


class Student {
  
//Declaring Private Variables
private:
    std::string StudentID;
    std::string FirstName;
    std::string LastName;
    std::string EmailAddress;
    int Age;
    int DaysInCourse[3];
    DegreeProgram DegreeProgram;

//Constructors
public:
    //New helper function to convert DegreeProgram enum to string
    std::string degreeToString(enum DegreeProgram degreeprogram);
    
    Student ();//empty constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, enum DegreeProgram degreeprogram);
    
//Declaring Accessor(Getter)
        std::string getStudentID();
        std::string getFirstName();
        std::string getLastName();
        std::string getEmailAddress();
        int getAge();
        int* getDaysInCourse();
        enum DegreeProgram getDegreeProgram();
    
//Declaring Mutatator(Setter)
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(enum DegreeProgram degreeprogram);
    

//Method to print Student information
    void printAll();
    

    
    //Destructor
    ~Student();

};
#endif
