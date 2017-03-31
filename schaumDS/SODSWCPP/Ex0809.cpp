//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.9 on page 162
//  Test driver for a HashTable class template

#include "HashTable.SC.hpp"
typedef HashTable<string,string> Table;
void print(const Table&);

int main()
{ Table t(5);
  t.insert("Ruf","cry");
  t.insert("Eis","ice");
  print(t);
  t.insert("Tor","gate");
  print(t);
  t.insert("Ast","branch");
  print(t);
  cout << "\nt[Ruf]=" << t["Ruf"] << "\n";
  t["Ruf"] = "shout";
  cout << "t[Ruf]=" << t["Ruf"] << "\n";
  t.remove("Ruf");
  print(t);
  t["Wal"] = "whale";
  t["Zug"] = "procession";
  t["Hof"] = "courtyard, farm";
  t["Rat"] = "advice, counsel";
  t["Lob"] = "praise";
  t["Mut"] = "courage";
  t["Tat"] = "action, deed";
  t["Ohr"] = "ear";
  t["Tor"] = "gate";
  t["Mal"] = "mark, sign";
  print(t);
}
void print(const Table& t)
{ cout << "\nsize=" << t.size()
       << "\tcapacity=" << t.capacity() << "\n";
  t.dump();
}
