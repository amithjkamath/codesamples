#include <iostream>
#include <vector>

//insertion sort assumes that prior sections of your array is sorted. Look at the next element. Do a binary search to find where it fits in, and insert it there. Move all the other elements one to the right before inserting. 

int findBinarySearch(const std::vector<int>& inArray, int key, int posLow, int posHigh)
{
	//search between posLow to posHigh.
    if(key < inArray[posLow])
    {
        return posLow;
    }
    if(key > inArray[posHigh])
    {
        return posHigh + 1;
    }
	// base case
	if(posLow >= posHigh)
	{
		return posLow;
	}
	int midPos = (posHigh - posLow)/2; // int will floor.
	if(key == inArray[posLow + midPos])
	{
		return midPos;
	}
	else if(key < inArray[posLow + midPos])
	{
		return posLow + findBinarySearch(inArray, key, posLow, midPos);
	}
	else
	{
		return posLow + findBinarySearch(inArray, key, posLow + midPos + 1, posHigh);
	}
}

void moveElements(std::vector<int>& inArray, int position, int maxPos)
{
    for(int idx = maxPos; idx > position; idx--)
    {
        inArray[idx] = inArray[idx-1];
    }
}

void insertionSort(std::vector<int>& inArray)
{
	for(int idx = 1; idx < inArray.size(); idx++)
	{
	    //traverse array from left to right, with a key
	    //check where in the sorted array the current element can be inserted
	    int key = inArray[idx];
	    int position = findBinarySearch(inArray, key, 0, idx-1);
	    // move all the elements to the right of location to be inserted, by one.
        std::cout << position << std::endl;
	    // if larger than all elements of sorted array, do nothing.
        if(position == idx)
        {
            // do nothing; it is sorted.
        }
        else
        {
            moveElements(inArray, position, idx);
            inArray[position] = key;
        }
	    // if smaller than all elements of sorted array, move all to right.
	    // repeat for elements 1 through end.
	}
}

void showArray(const std::vector<int> inArray)
{
	std::cout << "Array contains: {";
	for(auto i : inArray)
	{
		std::cout << i << ", ";
	}
	std::cout << "}" << std::endl;
}

int main()
{
	std::vector<int> testArray = {5, 2, 8, 3, 7, 4, 0};
	showArray(testArray);	
	insertionSort(testArray);
	showArray(testArray);

	std::cout << __FILE__ << " compiled on " << __DATE__ << std::endl;
	return 0;
}
