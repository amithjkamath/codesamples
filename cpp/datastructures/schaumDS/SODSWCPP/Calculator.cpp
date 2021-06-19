//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Calculator.cpp
//  Implementation of Calculator class

#include "Calculator.h";
#include <sstream>  // defines the istringstream class

istream& operator>>(istream& istr, Calculator& c)
{ string input;
  istr >> input;
  cout << output;  // echo input
  switch (input[0])
  { case '+': c.add();       break; 
    case '-': c.subtract();  break; 
    case '*': c.multiply();  break; 
    case '/': c.divide();    break; 
    default:
      istringstream in(input);  // converts input to stream
      in >> x;                  // reads double from stream
      oprnd.push(x);
  }
  return istr;
}

ostream& operator<<(ostream& ostr, const Calculator& c)
{ 
  
  
  return ostr << r._num << "/" << r._den;
}
