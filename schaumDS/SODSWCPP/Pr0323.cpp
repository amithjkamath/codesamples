//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.23 on page 66
//  A Purse class

#include <iomanip>
#include <iostream>
using namespace std;
void print(Purse);

class Purse
{ // instances represent purses containing coins
  public:
    Purse(int=0,int=0,int=0,int=0);
    int pennies() const;
    int nickels() const;
    int dimes() const;
    int quarters() const;
    float value() const;
    void insert(float);
    void remove(float);
    float empty();
    bool isEmpty() const;
  private:
    int _pennies;
    int _nickels;
    int _dimes;
    int _quarters;
    void reduce();
    //  INVARIANTS: 0 <= _pennies < 5
    //              0 <= _nickels < 2
    //              0 <= dimes < 3
    //              0 <= _quarters
};

////////////////////////////////////////////////////////////////
//  Test driver:

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

////////////////////////////////////////////////////////////////
//  Implementation of Purse class:

Purse::Purse(int pennies, int nickels, int dimes, int quarters)
  : _pennies(pennies), _nickels(nickels), _dimes(dimes),
    _quarters(quarters)
{ reduce();
}

int Purse::pennies() const { return _pennies; }

int Purse::nickels() const { return _nickels; }

int Purse::dimes() const { return _dimes; }

int Purse::quarters() const { return _quarters; }

float Purse::value() const
{ return 0.01*_pennies + 0.05*_nickels + 0.10*_dimes
                       + 0.25*_quarters;
}

void Purse::insert(float dollars)
{ _pennies += int(100*dollars);
  reduce();
}

void Purse::remove(float dollars)
{ _pennies -= int(100*dollars);
  reduce();
}

float Purse::empty()
{ float v = value();
  _pennies = _nickels = _dimes = _quarters = 0;
  return v;
}

bool Purse::isEmpty() const
{ return !(_pennies || _nickels || _dimes || _quarters);
}

void Purse::reduce()
{ int v = int(100*value());
  if (v < 0.00)
  { empty();
    return;
  }
  _quarters = v/25;
  v %= 25;
  _dimes = v/10;
  v %= 10;
  _nickels = v/5;
  v %= 5;
  _pennies = v;
}
