//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.7 on page 14
//  Amortizes a loan

#include <iomanip>    // defines setw() function
#include <iostream>   // defines cin and cout objects
using namespace std;  // obviates the std:: prefix

int main()
{ double amount, payment, rate, interest;
  cout << "Enter amount of loan (in $): ";   cin >> amount;
  cout << "Enter monthly payment (in $): ";  cin >> payment;
  cout << "Enter interest rate (as a %): ";  cin >> rate;
  rate /= 100;  // convert from percentage to decimal
  rate /= 12;   // convert annual rate to monthly rate
  cout << setw(6) << "\n Month  Interest    Amount\n";
  cout << setw(6) <<   " -----  --------   -------\n";
  cout << setiosflags(ios::fixed|ios::showpoint) << setprecision(2);
  cout << setw(6) << 0 << setw(20) << amount << "\n";
  for (int month=1; amount>0; month++)
  { interest = rate*amount;
    amount += interest;
    amount -= payment;
    cout << setw(6) << month
         << setiosflags(ios::fixed|ios::showpoint)
         << setprecision(2)
         << setw(10) << interest
         << setw(10) << (amount>0?amount:0) << "\n";
  }
  cout << setw(6) << " -----  --------    ------\n";
}
