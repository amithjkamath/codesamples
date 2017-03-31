//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.13 on page 85
//  Recursive function that prints permutations

void print(string s, int k, int n)
{ if (k == n) cout << s.substr(0,n) << endl;  // basis
  for (int i=k; i < n; i++)
    { swap(s[i], s[k]);
      print(s, k+1, n);  // recursion
      swap(s[i], s[k]);
    }
}
