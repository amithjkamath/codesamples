//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.23 on page 15
//  Tests strings for palindromes

#include <ctype.h>   // defines isalpha() and toupper()
#include <iostream>
using namespace std;
bool isPalindrome(string); 

int main()
{ string s;
  cout << "Enter a string: ";
  while (getline(cin,s))
  { cout << "The string \"" << s;
    if (isPalindrome(s)) cout << "\" is a palindrome!\n";
    else cout << "\" is a not palindrome.\n";
    cout << "Enter another string: ";
  }
}

bool isPalindrome(string s)
{ string ss=s;
  int k=0;
  for (int i=0; i<s.length(); i++)  // extract k letters
    if (isalpha(s[i])) ss[k++]=toupper(s[i]);
  s = ss.substr(0,k);  // use only first k characters
  for (int i=0; i<k/2; i++)
    if (ss[i] != ss[k-1-i]) return false;
  return true;
}
