#include <immintrin.h>
#include <iostream>
using namespace std;

int main()
{
    float out[8];
    float a[8] = { 0.0,1.0,2.0,3.0,4.0,5.0,6.0,7};
    __m256 test =  _mm256_load_ps(&a[0]);
    cout << "" << endl; // prints
    return 0;
}
