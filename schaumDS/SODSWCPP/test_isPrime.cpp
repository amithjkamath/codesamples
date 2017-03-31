#include <iostream>
using namespace std;

bool isPrime(int);
void generate(int);

int main()
{ for (int k=1; k<1000; k++)
    if (isPrime(k)) cout << k << " ";
  cout << endl;
  generate(19);   // 19 79 (319) 1279 5119 20479 81919
  generate(109);  // 109 439 1759 7039 (28159)
}

bool isPrime(int n)
{ if (n<2) return false;
  if (n<4) return true;
  for (int d=2; d<=n/2; d++)
    if (n%d==0) return false;
  return true;
}

void generate(int n)
{ for (int k=n; k<100000; k = 4*k+3)
    if (isPrime(k)) cout << k << " ";
    else cout << "(" << k << ") ";
  cout << endl;
}
