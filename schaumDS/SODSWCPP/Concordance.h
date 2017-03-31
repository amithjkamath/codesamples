//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Concordance.h
//  Interface for the Concordance class

#include <fstream>
#include <iostream>
#include <list>
#include <map>
using namespace std;

class Concordance
{ protected:
    typedef list<int> List;
    typedef map<string,List> Map;
    friend istream& operator>>(istream&, Concordance&);
    friend ostream& operator<<(ostream&, const Concordance&);
    friend ostream& operator<<(ostream& ostr, const List& l);
    Map _;
    bool extract(string&, string);
};
