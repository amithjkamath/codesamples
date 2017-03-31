//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Problem 1.24 on page 15
//  Right-justifies a text file

#include <fstream>
using namespace std;

int main()
{ const int WIDTH=60;
  ifstream in("Butler.txt");
  ofstream out("Butler.justified.txt");
  string s;
  while (getline(in,s))
    out << string(WIDTH-s.length(),' ') << s << "\n";
}
