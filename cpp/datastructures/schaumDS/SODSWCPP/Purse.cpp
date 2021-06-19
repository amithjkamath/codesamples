//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Purse.cpp
//  Implementation of Purse class

#include "Purse.h"

//////////////////////////////////////////////////////////////////////
//  public members:

Purse::Purse(int pennies, int nickels, int dimes, int quarters)
  : _pennies(pennies), _nickels(nickels), _dimes(dimes),
    _quarters(quarters)
{ reduce();
}

int Purse::pennies() const
{ return _pennies;
}

int Purse::nickels() const
{ return _nickels;
}

int Purse::dimes() const
{ return _dimes;
}

int Purse::quarters() const
{ return _quarters;
}

float Purse::value() const
{ return 0.01*_pennies + 0.05*_nickels + 0.10*_dimes + 0.25*_quarters;
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

//////////////////////////////////////////////////////////////////////
//  private members:

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

