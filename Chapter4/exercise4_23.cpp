#include<iostream>
#include<string>

int main(void)
{

std::string s = "word";

std::string pl = "";
pl = (s + s[s.size() - 1]) == 's' ? "" : "s";

std::cout << pl << std::endl;

return 0;
}