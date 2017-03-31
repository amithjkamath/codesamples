//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 8.4 on page 171
//  A HashTable class template with parameter for load factor

#include <fstream>
#include <iostream>
#include <list>
#include <map>
using namespace std;

template < class K, class T, float LOAD, class H=Hash<K> >
class HashTable
{ protected:
    typedef pair<K,T> Pair;
    typedef vector<Pair> Vector;
    typedef Vector::iterator VIt;
    typedef Vector::const_iterator CVIt;
    static const CAP=109;             // default initial capacity
  public:
    HashTable(int cap=CAP, const H& h=H()) : _(cap), _hash(h) { }
    T& operator[](K);  // subscript op for insertions and updates
    bool insert(K,T);                   // inserts the given pair
    bool remove(K);         // deletes the element with given key
    int size() const;              // number of elements in table
    int capacity() const { return _.size(); }  // number of lists
    void dump() const;          // displays the entire hash table
  protected:
    Vector _;                         // vector of lists of pairs
    H _hash;                              // hash function object
    int hash(K);         // hash function built from _hash object
    void rebuild();   // rebuilds the hash table making it larger
}:
