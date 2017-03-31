//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Person.h
//  Test driver for the Person class

#include "Person.h"

void print(Person);

int main()
{ Person p0;
  print(p0);
  Person p1("Smith");
  print(p1);
  Person p2("John","Smith");
  print(p2);
  Person p3("John","Smith",1977);
  print(p3);
  p3 = Person("Gaius","Julius","Caesar");
  p3.setYearOfDeath(-44);
  print(p3);
  Person p4("Anita","Huray","Hubbard",1944,8,18);
  print(p4);
  p4 = Person("John","Behrens","Hubbard",1972);
  print(p4);
  Person p5("Johann","Sebastian","Bach",1685,3,21,1750,7,28);
  print(p5);
  Person p6("Isaac","Newton",1642,1727);
  print(p6);
  Person p7("Alexander","Nevski",1218,1263);
  print(p7);
  Person p8("Sara","Rast","Hubbard",1917,8,15,1993,6,15);
  print(p8);  
}

void print(Person p)
{ cout << p;
  if (p.isAlive())
  { int age=p.age();
    if (age > -1) cout << " is " << p.age() << " years old";
    else cout << " is alive";
  }
  else
  { int aed=p.ageAtDeath();
    if (aed > -1) cout << " lived " << aed << " years";
    else cout << " is dead";
  }
  cout << ".\n";
}
