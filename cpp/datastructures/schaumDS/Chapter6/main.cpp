#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;

class Point {
public:
double x, y;
};
class Vector {
public:
Point start, end;
};

void printVector(Vector v) {
cout << "(" << v.start.x << "," << v.start.y << ") -> (" << v.end.x << "," << v.end.y << ")" << endl;
}

int main(void)
{
Vector vec1;
vec1.start.x = 3.0;
vec1.start.y = 4.0;
vec1.end.x = 5.0;
vec1.end.y = 6.0;
Vector vec2;

printVector(vec1);
return 0;
}