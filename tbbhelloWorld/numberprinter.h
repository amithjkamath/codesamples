#ifndef NUMBERPRINTER_H
#define NUMBERPRINTER_H

#include <tbb/blocked_range.h>
#include <vector>

using namespace std;
using namespace tbb;

class NumberPrinter {

  private:
    static char *develop(size_t i); // The private method develop(size_t i) is the one where we will perform our local computation.

  public:
    vector<char *> my_vect; // data member to store the output data of the computation.

    void operator ()(const blocked_range<size_t>& r); //method for describing the computation itself.

    //This is also called the split constructor. It is a copy constructor that includes a useless argument called split, that TBB uses and needs to distinguish it from the regular copy constructor. TBB calls this split constructor when it decides that there is too much data too be handled by a single core. It then creates a copy of one of the class instances, and distributes the data evenly among them (this is entirely transparent for the user, and its one of the many things that makes Intel TBB so cool).

    NumberPrinter(NumberPrinter& x, split); // ?? don't know what this is for. 
    NumberPrinter(int highbit); // this is the constructor.

    void join(const NumberPrinter& y); // this specifies how the data is joined back after parallelizing the computation in the () operator.
};
#endif //NUMBERPRINTER_H
