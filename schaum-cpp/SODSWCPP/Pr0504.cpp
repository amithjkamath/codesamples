//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 5.4 page 104
//  Testing the isPalindrome() function

#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(const string);

int main()
{ string s;
  cin >> s;
  if (isPalindrome(s)) cout << s << " is a palindrome.\n";
  else cout << s << " is NOT a palindrome.\n";
}

bool isPalindrome(const string s)
{ stack<char> stack;
  for (int i=0; i<s.length(); i++)
    stack.push(s[i]);
  for (int i=0; i<s.length(); i++)
    if (stack.top() != s[i]) return false;
    else stack.pop();
  return true;
}
