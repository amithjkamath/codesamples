#include "tbb/parallel_reduce.h"
#include "tbb/task_scheduler_init.h"
#include "numberprinter.h"

using namespace tbb;

void printNumbers(int n)
{
    // We then call the printNumbers(int n) function that creates a NumberPrinter object. Note that I give it 0 as a parameter: actually, in this code, I dont use the parameter at all (but youll need a one parameter constructor for Intel TBB to use parallel_reduce). 
    NumberPrinter p(n);

   // I then call the parallel_reduce(blocked_range(0,n), p, auto_partitioner()) function.
    parallel_reduce(blocked_range<size_t>(0,n),p,auto_partitioner());
}

int main(int argc, char* argv[])
{
    // first thing, you should initialize the Intel TBB library by creating a task_scheduler_init object. You should only use TBB during the lifespan of this object, so you may just put it at the beginning of your main.
    task_scheduler_init init;


    //
    printNumbers(1000);
    return 0;
}
