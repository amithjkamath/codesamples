//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Calculator.h
//  Interface for Calculator class

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <stack>    // defines the stack<T> class template
using namespace std;

class Calculator
{ // instances represent arithmetic calculators
  public:
    enum Op { PLUS, MINUS, TIMES, DIV };
    void enter(double);
    double add();
    double subtract();
    double multiply();
    double divide();
    
    
    Calculator(int=0);
    Calculator(int, int, int);
    Calculator(string);
    int day() const;
    int year() const;
    int month() const;
    int dayOfMonth() const;
    int dayOfYear() const;
    string dayOfWeek() const;
    string toString() const;
    static const Calculator Y2K;
    static Calculator today();
    Calculator& operator++();  // pre-increment
    Calculator& operator--();  // pre-decrement
    Calculator operator++(int);  // post-increment
    Calculator operator--(int);  // post-decrement
    Calculator& operator+=(const int);
    Calculator& operator-=(const int);
    bool operator<(const Calculator&) const;
    bool operator>(const Calculator&) const;
    bool operator<=(const Calculator&) const;
    bool operator>=(const Calculator&) const;
    bool operator==(const Calculator&) const;
    bool operator!=(const Calculator&) const;
  protected:
    stack<Op> operator;
    stack<double> operand;
    
    
  
    int _day;  // 0 = Dec 31 1600, 1 = Jan 1 1601
    static bool isLeap(const int);
    static int monthNumber(string);
    static string monthName(const int);
    static int daysInMonth(const int, const int);
    int yearNum() const;
    int quadyearNum() const;
    int centuryNum() const;
    int quadcenturyNum() const;
    void validate();  // CONSTRAINT: 0.0 <= _day
    static const int LY;  // = 365
    static const int LQY;  // = 1461
    static const int LC;  // = 36524
    static const int LQC;  // = 146097
    static const int BASE_YEAR;  // = 1601
};

#endif  // CALCULATOR_H
