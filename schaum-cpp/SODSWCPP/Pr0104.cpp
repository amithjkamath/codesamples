//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.4 on page 13
//  Syllables of the diatonic scale

#include <iostream>
using namespace std;

int main()
{ // prints the syllable for a given tone:
  char tone;
  string syllable;
  cout << "Enter the tone (e.g. G): ";
  cin >> tone;
  switch (tone)
  { case 'A': syllable = "la";  break;
    case 'B': syllable = "ti";  break;
    case 'C': syllable = "do";  break;
    case 'D': syllable = "re";  break;
    case 'E': syllable = "mi";  break;
    case 'F': syllable = "fa";  break;
    case 'G': syllable = "so";  break;
    default : syllable = "error";
  }
  cout << "The syllable for " << tone << " is \""
       << syllable << "\".\n";
}
