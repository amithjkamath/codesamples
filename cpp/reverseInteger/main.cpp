#include <iostream>

using namespace std;

int reverse(int x) {
    // find number of digits in input.
    if(x >= INT_MAX)
        return 0;

    bool isNegative = false;
    if(x < 0)
    {
        x = -x;
        isNegative = true;
    }

    long powerLessThan = 1;
    int numDigits = 0;
    while(x >= powerLessThan)
    {
        powerLessThan *= 10;
        numDigits++; // 10
    }

    if(numDigits > 1)
        powerLessThan = powerLessThan/10;
    int outNumber = 0;
    int reverseIdx = 1;
    // number has numDigits digits.
    for(int idx = 0; idx < numDigits; idx++)
    {
        int digit = x/powerLessThan;
        outNumber += reverseIdx*digit;
        x -= digit*powerLessThan;
        reverseIdx*= 10;
        powerLessThan/= 10;
    }
    // go in a reverse loop: 10^digits. extract largest digit.
    // add as smallest digit of output.
    // loop through the whole number.
    if(isNegative)
        outNumber = -outNumber;
    return outNumber;
}

int main() {
    cout << reverse(1534236469) << endl;
    return 0;
}