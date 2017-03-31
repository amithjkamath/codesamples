//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Person.h
//  Implementation of Person class

#include "Person.h"

//////////////////////////////////////////////////////////////////////
//  friend functions:

ostream& operator<<(ostream& ostr, const Person& person)
{ return ostr << person.toString();
}

//////////////////////////////////////////////////////////////////////
//  public members:

Person::Person(string lname)
  : _lname(lname), _dob(0), _dod(0), _yob(0), _yod(0) { }

Person::Person(string fname, string lname, int yob, int yod)
  : _fname(fname), _lname(lname),
    _dob(0), _dod(0), _yob(yob), _yod(yod) { }
 
Person::Person(string fname, string mname, string lname,
  int yob, int yod) : _fname(fname), _mname(mname), _lname(lname),
  _dob(0), _dod(0), _yob(yob), _yod(yod) { }
 
Person::Person(string fname, string mname, string lname,
  int yob, int mob, int dob, int yod, int mod, int dod)
  : _fname(fname), _mname(mname), _lname(lname),
    _dob(new Date(yob,mob,dob)), _dod(0), _yob(yob), _yod(yod)
{ if (yod && mod && dod) _dod = new Date(yod,mod,dod);
}

string Person::toString() const
{ ostringstream out;
  out << name();
  if(_dob)
  { out << " (" << *_dob;
    if (_dod) out << "-" << *_dod;
    out << ")";
  }
  else if(_yob)
  { out << " (" << _yob;
    if (_yod) out << "-" << _yod;
    out << ")";
  }
  string s = out.str();
  if (s.length()) return s;
  return "[NO NAME]";
}

string Person::firstName() const
{ return _fname;
}

string Person::middleName() const
{ return _mname;
}

string Person::lastName() const
{ return _lname;
}

string Person::name() const
{ ostringstream out;
  if (_fname.length() > 0) out << _fname << " ";
  if (_mname.length() > 0) out << _mname << " ";
  out << _lname;
  return out.str();
}

char Person::sex() const
{ if (_sex == 'F') return 'F';
  return _sex;
}

Date* Person::dateOfBirth() const
{ return _dob;
}

Date* Person::dateOfDeath() const
{ return _dod;
}

int Person::yearOfBirth() const
{ return _yob;
}

int Person::yearOfDeath() const
{ return _yod;
}

void Person::setFirstName(string fname)
{ _fname = fname;
}

void Person::setMiddleName(string mname)
{ _mname = mname;
}

void Person::setLastName(string lname)
{ _lname = lname;
}

void Person::setSex(char sex)
{ _sex = sex;
}

void Person::setDateOfBirth(int y,int m, int d)
{ _dob = new Date(y,m,d);
}

void Person::setDateOfDeath(int y,int m, int d)
{ _dod = new Date(y,m,d);
}

void Person::setYearOfBirth(int yob)
{ _yob = yob;
}

void Person::setYearOfDeath(int yod)
{ _yod = yod;
}

bool Person::isAlive()
//{ return (_yob > 0 && _yod == 0);
{ return ( _yod == 0);
}

int Person::age()
{ if (!isAlive()) return -1;
  if (_dob) return int((Date::today()-*_dob)/365.2425);
  if (_yob) return int(Date::today().year()-_yob);
  return -1;
}

int Person::ageAtDeath()
{ if (_dob && _dod) return int((*_dod-*_dob)/365.2425);
  if (_yob && _yod) return int(_yod-_yob);
  return -1;
}
