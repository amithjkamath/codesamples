//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 8.3 on page 171
//  A frequency list of words

#include <fstream>
#include <iostream>
#include <list>
#include <map>
using namespace std;

class FrequencyList
{ protected:
    typedef map<string,int> Map;
    friend ifstream& operator>>(istream&, FrequencyList&);
    friend ostream& operator<<(ostream&, const FrequencyList&);
    Map _;
    bool extract(string&, string);
};

int main()
{ ifstream fin("Shakespeare.txt");
  ofstream fout("FrequencyList.out");
  FrequencyList c;
  fin >> c;
  fout << c;
  cout << c;
}

ifstream& operator>>(istream& istr, FrequencyList& c)
{ typedef FrequencyList::Map::iterator CMIt;
  string line, word;
  for (int n=1; getline(istr,line); n++)
    while (c.extract(word,line))
    { CMIt it=c._.find(word);
      if (it == c._.end()) c._[word] = 1;  // insert it
      else ++(c._[word]);                  // count it
    }
}

ostream& operator<<(ostream& ostr, const FrequencyList& c)
{ typedef FrequencyList::Map::const_iterator CMCIt;
  for (CMCIt it=c._.begin(); it!=c._.end(); it++)
    ostr << it->first << ": " << it->second << '\n';
  return ostr;
}

bool FrequencyList::extract(string& word, string line)
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
