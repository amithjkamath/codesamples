//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Person.h
//  Interface for Person class

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <sstream>
#include "Date.h"
using namespace std;

class Person
{ // instances represent people
    friend ostream& operator<<(ostream&, const Person&);
  public:
    Person(string="");
    Person(string,string,int=0,int=0);
    Person(string,string,string,int=0,int=0);
    Person(string,string,string,int,int,int,int=0,int=0,int=0);
    string toString() const;
    string firstName() const;
    string middleName() const;
    string lastName() const;
    string name() const;
    char sex() const;
    Date* dateOfBirth() const;
    Date* dateOfDeath() const;
    int yearOfBirth() const;
    int yearOfDeath() const;
    void setFirstName(string);
    void setMiddleName(string);
    void setLastName(string);
    void setSex(char);  // 'M' || 'F'
    void setDateOfBirth(int,int,int);  // (yyyy,mm,dd)
    void setDateOfDeath(int,int,int);  // (yyyy,mm,dd)
    void setYearOfBirth(int);
    void setYearOfDeath(int);
    bool isAlive();
    int age();
    int ageAtDeath();
  protected:
    string _fname;  // e.g., "John"
    string _mname;  // e.g., "", meaning "none known"
    string _lname;  // e.g., "Smith"
    char _sex;      // e.g., 'M'
    Date* _dob;     // e.g., &Date(1977,07,04);
    Date* _dod;     // e.g., 0, meaning "unknown"
    int _yob;       // e.g., 1977
    int _yod;       // e.g., 0, meaning "unknown"
};

#endif  // PERSON_H
