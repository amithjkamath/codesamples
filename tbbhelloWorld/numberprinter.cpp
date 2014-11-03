#include "numberprinter.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Youll notice when running the code on several CPUs that most of the time, numbers are not displayed in the right order: thats because several develop(i) methods are concurrently running from several instances of the class.

char * NumberPrinter::develop(size_t i)
{
    cout << i << endl;
    char *foo=(char*) malloc((log2(i)+3)*sizeof(char));
    sprintf(foo, "s%d", i);
    return foo;
}

// The operator(const blocked_range& r) override is used by Intel TBB, as its the function that is called to loop through the items assigned to this instance of the class. TBB uses a blocked_range<size_t> to present the data to class instances. Here, we just call develop(i) on every item, and save the result in my_vector.

void NumberPrinter::operator()( const blocked_range<size_t>& r) {
    for(size_t i=r.begin(); i!=r.end(); ++i)
        my_vect.push_back(develop(i));
}

NumberPrinter::NumberPrinter( NumberPrinter& x, split) {}
NumberPrinter::NumberPrinter(int highbit) {}

// Finally, the join(const NumberPrinter& y) method is the one that is called by TBB when all the local computations are done on several processes that manage adjacent data in the original blocked_range. TBB will always call join(const NumberPrinter& y) in the order in which the data has been distributed. For instance, if processes a, b and c are all given a third of the data (in that order), then a will always join with b and b with c. This can be easily checked: just print my_vector after the joining has been done and youll notice that in there, all the elements are sorted.

void NumberPrinter::join(const NumberPrinter& y) {
    my_vect.reserve(my_vect.size()+  y.my_vect.size());
    for (int i=0; i<y.my_vect.size(); ++i)
            my_vect.push_back(y.my_vect.at(i));
//  my_vect.insert(my_vect.end(), y.my_vect.begin(), y.my_vect.end());
}
