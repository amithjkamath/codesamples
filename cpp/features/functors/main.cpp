#include <iostream>


// A functor is a class that has overloaded the operator().
// What this does is that it makes an object of this class behave like a function
// You can pass values to the () operator, and the class will combine this information
// with it's internal state to generate useful results. For example, a functor can
// be setup to perform additions based on some initial state.
class addx
{
// this class holds state in _x, which is initialized through it's constructor.
public:
    addx(int x) {_x = x;}; // this is the inline constructor for this class.
    int operator()(int value) {return _x + value;}; // this overload is what makes this class a functor.
private:
    int _x; // this is some internal state stored in this class.
};

int main() {
    std::cout << __FILE__ << " compiled on " << __TIME__ << " " << __DATE__ << std::endl;

    addx add3(3); // creating add3(3) here is calling it's constructor, and setting _x to be 3.
    // the name of the object can be setup such that it alludes to what the functor does.
    std::cout << add3(24) << std::endl; // this invocation is the overload. It is different
    // from the class constructor, and this is the 'functional' way of running it.

    addx add5(5);
    std::cout << add5(5) << std::endl;

    return 0;
}