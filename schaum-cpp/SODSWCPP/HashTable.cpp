//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999

#include <fstream>
#include <iostream>
#include <list>
#include <map>
using namespace std;

template <class H, int C>
class HashTable
{   friend ifstream& operator>>(istream&, HashTable&);
    friend ostream& operator<<(ostream&, const HashTable&);
 public:
   HashTable(int cap=C) : _cap(cap), _(Vector(cap)) { }
   int size() const { return _size; }
   int cap() const { return _cap; }
   string& operator[]();  // find
 protected:
   typedef pair<string,string> Pair;
   typedef vector<Pair> Vector;
   Vector _;   // table
   int _size;  // number of objects in table
   int _cap;   // capacity == maximum size
};

struct Hash
{ int operator()(string s)
  { int h=0;
    for (int i=0; i<s.length(); i++)
      h += s[i];
    return h%_cap;
  }
};

int main()
{ ifstream fin("Planets.dat");
  HashTable t(11);
  fin >> t;
  cout << t;
}

template <class H>
ifstream& operator>>(istream& istr, HashTable& t)
{ H hash;
  string line, key, value;
  while (getline(istr,line))
  { int len=line.find("\t");
    key = line.substr(0,len);    // name of planet
    value = line.substr(len+1);  // data on planet
    int k=hash(key);
    t._[k] = HashTable::Pair(key,value);
    ++(t._size);
  }
}

template <class H>
ostream& operator<<(ostream& ostr, const HashTable& c)
{ for (int k=0; k<c._cap; k++)
  { HashTable::Pair p=c._[k];
    string key=p.first, value=p.second;
    if (key.length()>0)
      ostr << k << '\t' << key << "\t\t" << value << '\n';
  }
}
