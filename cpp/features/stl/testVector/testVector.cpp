#include <iostream>
#include <vector>

typedef std::vector<int> intVector;
typedef std::vector<intVector> vecVector;
int main(void)
{
	intVector aVector;
	std::cout << "Size of aVector is " << aVector.size() << std::endl;
	
	aVector.push_back(5);
	aVector.push_back(6);
	
	std::cout << "Size of aVector is now " << aVector.size() << std::endl;
	std::cout << "aVector(0) " << aVector[0] << std::endl;
	std::cout << "aVector(1) " << aVector[1] << std::endl;
	
	std::cout << "removing the last element" << std::endl;
	
	aVector.pop_back();
	
	std::cout << "Size of aVector is now " << aVector.size() << std::endl;
	
	std::cout << "Last element in aVector is " << aVector.back() <<std::endl;
	
	vecVector vectorOfVector;
	vectorOfVector.push_back(aVector);
	intVector anotherVector(4,100);
	vectorOfVector.push_back(anotherVector);
	
	std::cout << "Size of vectorOfVector is " << vectorOfVector.size() << std::endl;
	
	std::cout << "vectorOfVector(1).(0) is " << vectorOfVector[1].front() << std::endl;
	return 0;
}