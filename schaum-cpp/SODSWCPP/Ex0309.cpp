//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.9 on page 56
//  Interface for Random class

class Random
{ public:
    Random(unsigned long=0);
    void reset_seed(unsigned long=0);
    int integer(unsigned long=ULONG_MAX,unsigned long=1);
    double real();
  private:
    unsigned long _seed;  // INVARIANT: 0 <= _seed < ULONG_MAX
    void randomize();
};
