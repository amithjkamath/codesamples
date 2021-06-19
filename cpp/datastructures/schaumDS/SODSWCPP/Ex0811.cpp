//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.11 on page 165
//  A permutation-insensitive hash function

void print(const string&);
const int SIZE=13;
int a[SIZE]={0};
int collisions=0;

int main()
{ print("Ruf");
  print("Eis");
  print("Tor");
  print("Ast");
  print("Zug");
  print("Hof");
  print("Rat");
  print("Lob");
  print("Mut");
  print("Tat");
  print("Ohr");
  print("Mal");
  cout << "\n\t" << collisions << " collisions\n";
}

void print(const string& s)
{ Hash<string> h;
  int n=h(s)%SIZE;
  cout << "h(" << s << ") = " << n << "\n";
  if (a[n]>0) ++collisions;
  ++a[n];
}