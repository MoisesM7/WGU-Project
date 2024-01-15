//
//  main.cpp
//  C867: Class Roster
//
//  Created by Moises Mercado on 12/2/23.
//
#include "degree.hpp"
#include "student.hpp"
#include "roster.hpp"
#include <string>

#include <iostream>



int main() {
    
//Declaring Course,Programming language, WGUstudent ID, and Name
    const std::string courseTitle = "C867: Scripting and Programming Applications";
    const std::string programingLanguage = "C++";
    const std::string WguStudentID = "010550703";
    const std::string studentName = "Moises Mercado";
    
    // Creating an instance of the Roster Class
    Roster classRoster;
    
   //Student Data
    const std::string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2, Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Moises,Mercado,momopvhs57@gmail.com,25,30,20,40,SOFTWARE"
    };
    
    //Adding each student to the roster
    for ( const auto& data : studentData){
        classRoster.parseAndAddStudent(data);
    }
    
    //Printing Course,Programming language, WGUstudent ID, and Name
    std::cout << "Course: " << courseTitle << std:: endl;
    std::cout << "Programming Language: " << programingLanguage << std:: endl;
    std::cout << "WGU Student ID:  " << WguStudentID << std:: endl;
    std::cout << "Name:  " << studentName << std:: endl;
    
  //Printing all student data
    std::cout << "\nDisplaying All Students:\n";
    classRoster.printAll();
    
    //Printing invlaid emails
    std::cout << "\nDisplaying Invalid Emails:\n";
    classRoster.printInvalidEmails();
    
    //Looping through classRosterArray and for each element, print average days in course
    std::cout << "\nDisplaying Average Days in Course:\n";
    for (int i = 0; i <= classRoster.getlastIndex(); ++i){
        classRoster.printAverageDaysInCourse(classRoster.getclassRosterArray()[i]->getStudentID());
    }

    //Printing student information for the Software degree program
    std::cout <<"\nStudents in Software Program:\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    
    //Removing a student with Id A3 and print the updated roster
    std::cout << "\nRemove Student A3 and Print All Students:\n";
    classRoster.remove("A3");
    classRoster.printAll();
    
    //Attempting to remove a non-existent student with ID "A3" and print message
    std::cout << "\nAttempt to Remove again:\n";
    classRoster.remove("A3");


    
    return 0;
}



