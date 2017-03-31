//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.6 on page 160
//  Implementation of a Concordance class

#include "Concordance.h"

ifstream& operator>>(istream& istr, Concordance& c)
{ typedef Concordance::Map::iterator CMIt;
  string line, word;
  for (int n=1; getline(istr,line); n++)
    while (c.extract(word,line))
    { CMIt it=c._.find(word);
      if (it == c._.end())       // new word
      { Concordance::List list;  // new list
        list.push_back(n);
        c._[word] = list;  // inserts new (word,list) pair into c
      }
      else // word is already in concordance
      { Concordance::List& list = it->second;  // its list
            if (n > list.back()) list.push_back(n);
      }
    }
}

ostream& operator<<(ostream& ostr, const Concordance& c)
{ typedef Concordance::Map::const_iterator CMCIt;
  for (CMCIt it=c._.begin(); it!=c._.end(); it++)
    ostr << it->first << ": " << it->second << '\n';
  return ostr;
}

ostream& operator<<(ostream& ostr, const Concordance::List& l)
{ typedef Concordance::List::const_iterator CLCIt;
  if (l.empty()) return ostr;
  CLCIt it=l.begin();
  ostr << *it;
  while (++it!=l.end())
    ostr << ", " << *it;
  return ostr;
}

bool Concordance::extract(string& word, string line)
{ static int p=0;       // points to next character to be processed
  while (p<line.length() && !isalpha(line[p]))
    ++p;                         // look for beginning of next word
  if (p == line.length())   // there are no more words on this line
  { p = 0;      // begin at the beginning of next line on next call
    return false;           // this call found no word on this line
  }
  int start=p;                    // points to first letter of word
  while (isalpha(line[p]))                      // find end of word
    ++p;
  int len=p-start;                  // word = line[start:start+len]
  word = string(len,' ');       // allocate len characterss to word
  for (int i=0; i<len; i++)               // extract word from line
    word[i] = toupper(line[start+i]);         // capitalize letters
  while (p<line.length() && !isspace(line[p]))
    ++p;                   // eat extraneous suffixes, such as "'s"
  return true;
}
