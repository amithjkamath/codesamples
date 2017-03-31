//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.22 on page 66
//  Prints the time

#include <ctime>  // defines the time() function
#include <iostream>
using namespace std;

int main()
{ for (int i=0; i<10; i++)
  { cout << "time(NULL) = " << time(NULL) << "\n";
    for (int j=0; j<20000; j++)
      time(NULL);
  }
}
