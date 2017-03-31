#include <iostream>
#include <string>
using namespace std;

bool ispalindrome(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

string shortestPalindrome(string s) {
    int pivotIdx = 0;
    string tempS = s;
    while(!ispalindrome(tempS))
    {
        if(s.size() == pivotIdx)
        {
            tempS = string("");
            break;
        }
        pivotIdx++;
        tempS = s.substr(0, s.size()-pivotIdx);
    }

    if(tempS.size() == 1)
    {
        string revS;
        revS = s.substr(1, s.size()-1);
        reverse(revS.begin(), revS.end());
        return revS+s;
    }
    else
    {
        string revS = s.substr(s.size()-pivotIdx, pivotIdx);
        reverse(revS.begin(), revS.end());
        return revS+s;
    }
}

int main() {
    std::cout << shortestPalindrome("asdf") << std::endl;
    std::cout << shortestPalindrome("aacecaaa") << std::endl;
    std::cout << shortestPalindrome("sasod") << std::endl;
    return 0;
}