#include <iostream>

class person
{
public:
    std::string _name;
    int _age;

    person(std::string, int);
    inline std::string getName(void) { return _name; }; // these are inline functions.
    int getAge(void); // this is the declaration.

    void show(void)
    {
        std::cout << "I'm " << _name << " and I'm " << _age << " years old." << std::endl;
    }
};

person::person(std::string name, int age)
{
    _name = name;
    _age = age;
}

int person::getAge(void)
{
    return _age;
}

class student : public person
{
public:
    int _gradeAttended;
    student(std::string, int, int);

    void show(void) // overridden function.
    {
        std::cout << "I'm " << _name << " and I'm " << _age << " years old. I have attended " << _gradeAttended << " classes." << std::endl;
    }
};

student::student(std::string name, int age, int gradeAttended)
:person(name, age) // initializer list, for parent class component.
{
    _gradeAttended = gradeAttended;
}

using namespace std;

int main() {
    std::cout << __FILE__ << " compiled at " << __TIME__ << std::endl;

    person alfred = person("Alfred", 5);
    alfred.show();

    person william = person("William", 36);
    william.show();

    student amith = student("Amith", 28, 14);

    amith.show();
    return 0;
}