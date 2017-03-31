//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.9 on page 85
//  Recursive function that tests form palindromes

bool isPalindrome(string s)
{ int len = s.length();
  if (len == 1) return true;               // basis
  if (len == 2) return (s[0] == s[1]);     // basis
  return isPalindrome(s.substr(1,len-2));  // recursion
}
