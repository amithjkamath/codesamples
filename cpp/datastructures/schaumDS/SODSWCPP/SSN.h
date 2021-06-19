//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  SSN.h
//  Defines SSN class for U.S. Social Security numbers

#include <iostream>
using namespace std;

class SSN : public string
{ // instances represent U.S. Social Security numbers
  friend ostream& operator<<(ostream& ostr, const SSN& ssn)
  { return ostr << ssn.s.substr(0,3) << "-"
                << ssn.s.substr(3,2) << "-" << ssn.s.substr(5,4);
  }
  public:
    SSN(string str) : s(str)
    { if (!isValid(s)) s = "000000000";
    }
    SSN() {  }
  private:
    string s;
    static bool isValid(string s)
    { if (s.length() != 9) return false;
      for (int i=0; i<9; i++)
        if (s[i] < '0' || s[i] > '9') return false;
      return true;
    }
};
