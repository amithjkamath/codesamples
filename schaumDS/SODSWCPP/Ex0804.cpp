//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.4 on page 158
//  Interface for a Concordance class

#include <fstream>
#include <iostream>
#include <list>
#include <map>
using namespace std;

class Concordance
{ protected:
    typedef list<int> List;
    typedef map<string,List> Map;
    friend ifstream& operator>>(istream&, Concordance&);
    friend ostream& operator<<(ostream&, const Concordance&);
    friend ostream& operator<<(ostream& ostr, const List& l);
    Map _;
    bool extract(string&, string);
};
