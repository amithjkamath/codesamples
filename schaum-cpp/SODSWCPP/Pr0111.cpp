//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.11 on page 15
//  Tests a function that converts Fahrenheit to Celsius:

#include <iostream>
using namespace std;

float celsius(float); 

int main()
{ for (int x=2; x<232; x += 10)
    cout << x << "\t" << celsius(x) << "\n";
}

float celsius(float x)
{ return 5.0/9.0*(x-32);
}
