#include <iostream>
#include <vector>

using namespace std;

void displayArray(std::vector<int>& inArray)
{
    for(int i = 0; i < inArray.size(); i++)
        std::cout <<  inArray[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void bubblesort(std::vector<T>& inArray)
{
	unsigned long len = inArray.size();
    unsigned long last;
	T value;
	for(last = len-1; last > 0; last--)
	{
		for( int currIdx = 0; currIdx < last; currIdx++)
		{
			if(inArray[currIdx] > inArray[currIdx+1])
			{
				//swap
				value = inArray[currIdx];
				inArray[currIdx] = inArray[currIdx+1];
				inArray[currIdx+1] = value;
			}
		}
	}
}

int main() {
    cout << __FILE__ << " compiled at " << __TIME__ << endl;

    std::vector<int> testArray = {1, 3, 2, 4, 6, 5};

    // show the array before sorting.
    displayArray(testArray);
    // sort the array.
    bubblesort<int>(testArray);
    // show the array after sorting.
    displayArray(testArray);

    return 0;
}