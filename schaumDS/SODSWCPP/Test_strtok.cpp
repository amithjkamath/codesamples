#include <iostream>
using namespace std;

int main()
{ char* buffer = "Jun 14, 1999";
  cout << "string(buffer) = [" << string(buffer) << "]\n";
  char* p = strtok(buffer, " ,");
  cout << "string(p) = [" << string(p) << "]\n";
  string s(p);
  cout << "s = [" << s << "]\n";
  s[0] = toupper(s[0]);
  s[1] = toupper(s[1]);
  s[2] = toupper(s[2]);
  cout << "s = [" << s << "]\n";
  p = strtok(NULL, " ,");
  cout << "string(p) = [" << string(p) << "]\n";
  cout << "atoi(p) = [" << atoi(p) << "]\n";
  int m = atoi(p);
  cout << "m = " << m << "\n";
  p = strtok(NULL, " ,");
  cout << "string(p) = [" << string(p) << "]\n";
  cout << "atoi(p) = [" << atoi(p) << "]\n";
  int n = atoi(p);
  cout << "n = " << n << "\n";
}
