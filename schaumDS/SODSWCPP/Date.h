//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Date.h
//  Interface for Date class

#ifndef DATE_H
#define DATE_H
#include <ctype.h>  // defines atoi(), atof(), and toupper() functions
#include <iostream>
#include <sstream>  // defines ostringstream class
using namespace std;

class Date
{ // instances represent calendar dates
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
    friend int operator-(const Date&, const Date&);
    friend Date operator+(const Date&, const int);
    friend Date operator-(const Date&, const int);
  public:
    Date(int=0);
    Date(int, int, int);
    Date(string);
    int day() const;
    int year() const;
    int month() const;
    int dayOfMonth() const;
    int dayOfYear() const;
    string dayOfWeek() const;
    string toString() const;
    static const Date Y2K;
    static Date today();
    Date& operator++();  // pre-increment
    Date& operator--();  // pre-decrement
    Date operator++(int);  // post-increment
    Date operator--(int);  // post-decrement
    Date& operator+=(const int);
    Date& operator-=(const int);
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
  private:
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

#endif  // DATE_H
