//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.3 on page 157
//  A German-English Dictionary

#include <iostream>
#include <map>
using namespace std;
typedef map<string,string> Dictionary;

int main()
{ Dictionary d;
  d["Tag"] = "day";
  d["Hut"] = "hat";
  d["Tal"] = "valley";
  d["Hof"] = "court, courtyard, farm";
  d["Uhr"] = "clock";
  d["Mut"] = "courage";
  d["Tat"] = "action, act, deed";
  d["Rad"] = "wheel";
  d["Bau"] = "building";
  d["Ohr"] = "ear";
  d["Tor"] = "gate";
  d["Ehe"] = "marriage";
  d["Mal"] = "mark, sign, time";
  for (Dictionary::iterator it=d.begin(); it!=d.end(); it++)
    cout << it->first << " = " << it->second << '\n';
}
