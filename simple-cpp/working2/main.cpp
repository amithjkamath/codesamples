#include <iostream>

class foo
{
public:
    foo(const foo & other); // copy constructor.
};

int main() {

    foo f1;
    return 0;
}