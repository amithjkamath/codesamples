//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Time.h
//  Interface for Time class

#ifndef TIME_H
#define TIME_H
#include <ctype.h>  // defines atoi() and atof() functions
#include <iostream>
#include <sstream>  // defines ostringstream class
using namespace std;

class Time
{ // instances represent 24-hour times of the day
    friend ostream& operator<<(ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);
    friend Time operator+(const Time&, const Time&);
    friend Time operator-(const Time&, const Time&);
    friend Time operator+(const Time&, const double);
    friend Time operator-(const Time&, const double);
  public:
    Time(double=0.0);
    Time(int, int, double=0.0);
    Time(string);
    int hour() const;
    int minute() const;
    double second() const;
    double hours() const;
    double minutes() const;
    double seconds() const;
    string toString() const;
    static const Time MIDNIGHT;
    static const Time NOON;
    static Time now();
    Time& operator++();  // pre-increment
    Time& operator--();  // pre-decrement
    Time operator++(int);  // post-increment
    Time operator--(int);  // post-decrement
    Time& operator+=(const Time&);
    Time& operator-=(const Time&);
    Time& operator+=(const double);
    Time& operator-=(const double);
    bool operator<(const Time&) const;
    bool operator>(const Time&) const;
    bool operator<=(const Time&) const;
    bool operator>=(const Time&) const;
    bool operator==(const Time&) const;
    bool operator!=(const Time&) const;
  private:
    double _sec;  // number of seconds elapsed since MIDNIGHT
    static double sec(int,int,double);
    void validate();  // CONSTRAINT: 0.0 <= _sec < 86,400.0
    static const double SECONDS_PER_DAY;  // = 86,400
};

#endif  // TIME_H