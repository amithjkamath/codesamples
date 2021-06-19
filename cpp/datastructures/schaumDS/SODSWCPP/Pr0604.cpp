//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.4 page 121
//  A clear() function for queues

void queue::clear()
{ while (!empty())
    pop();
}
