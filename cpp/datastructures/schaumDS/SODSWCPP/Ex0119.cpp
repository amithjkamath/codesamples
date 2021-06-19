//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.19 on page 12
//  Capitalizing the words of a file

#include <ctype.h>   // defines isalpha() function
#include <fstream>   // defines ifstream and ofstream classes

int main()
{ ifstream infile("input.txt");
  ofstream outfile("output.txt");
  string line;
  while (getline(infile,line))
  { for (int i=0; i<line.length(); i++)
      if (i==0 || line[i-1] == ' ' && isalpha(line[i])) 
        line[i] = toupper(line[i]);
    outfile << line << endl;
  }
}
