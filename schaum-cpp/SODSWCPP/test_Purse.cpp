//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Purse.cpp
//  Test driver for Purse class

#include <iomanip>
#include "Purse.h"
void print(Purse);

int main()
{ Purse purse(20,10,10,5);
  print(purse);
  purse.insert(0.97);
  print(purse);
  purse.remove(1.14);
  print(purse);
  purse.remove(3.33);
  print(purse);
}

void print(Purse purse)
{ cout << "purse.value() = " << purse.value() << "\n\n";
  if (purse.isEmpty()) cout << "  The purse is empty.\n";
  else cout << setw(3) << purse.pennies()  << " pennies   = "
            << 0.01*purse.pennies() << "\n"
            << setw(3) << purse.nickels()  << " nickels   = "
            << 0.05*purse.nickels() << "\n"
            << setw(3) << purse.dimes()    << " dimes     = "
            << 0.10*purse.dimes() << "\n"
            << setw(3) << purse.quarters() << " quarters  = "
            << 0.25*purse.quarters() << "\n\n";
}
