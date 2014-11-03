#include <iostream>

#include "tbb/blocked_range.h"
#include "tbb/parallel_for.h"

using namespace tbb;

#define ARRSIZE 1000

void apply_transformation(int* x)
{
    *x = 2*(*x);
}

class apply_transform
{
    int* array;
  public:
    apply_transform(int* a): array(a) {}
    void operator()(const blocked_range<int>& r) const
    {
        for(int i = r.begin(); i < r.end(); ++i)
            apply_transformation(&array[i]);
    }
};

void do_parallel_tbb(int* array, int size)
{
    parallel_for(blocked_range<int>(0,size), apply_transform(array));
}

int main()
{
    int inArray[ARRSIZE] = {0};
    for(int i = 0; i < ARRSIZE; ++i)
        inArray[i] = i;

    for(int j = 0; j < ARRSIZE; ++j)
        std::cout << inArray[j] << " ";
    std::cout << std::endl;

    std::cout << "Processing in parallel ... " << std::endl;

    do_parallel_tbb(inArray,ARRSIZE);

    for(int k = 0; k < ARRSIZE; ++k)
        std::cout << inArray[k] << " ";
    std::cout << std::endl;
    

}
