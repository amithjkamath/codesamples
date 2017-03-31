#include <iostream>
#include <vector>

using namespace std;

void displayArray(std::vector<int>& inArray)
{
    std::cout << " Array = { ";
    for(int idx = 0; idx < inArray.size()-1; idx++)
    {
        std::cout << inArray[idx] << ", ";
    }
    std::cout << inArray[inArray.size()-1] << " }" << std::endl;
}

void insertionSort(std::vector<int>& inArray)
{
    for(int eIdx = 0; eIdx < inArray.size(); eIdx++)
    {
        int toCompare = inArray[eIdx];
        for(int sIdx = 0; sIdx < eIdx; sIdx++)
        {
            if(inArray[sIdx] >= toCompare)
            {
                int foundIdx = sIdx;
                int temp = inArray[foundIdx];
                inArray[foundIdx] = toCompare;
                for (int inIdx = eIdx; inIdx > foundIdx; inIdx--) {
                    inArray[inIdx] = inArray[inIdx-1];
                }
                inArray[foundIdx+1] = temp;
                break;
            }
        }
    }
    return;
}

int main() {

    std::cout << __FILE__ << " compiled at " << __TIME__ << std::endl;
    // create test array
    std::vector<int> testArray = {1, 3, 2, 4, 3, 5, 7, 6, 0};
    // display before sorting
    displayArray(testArray);
    // sort
    insertionSort(testArray);
    // display after sorting
    displayArray(testArray);

    testArray = {2, 2, 2, 2, 2};
    // display before sorting
    displayArray(testArray);
    // sort
    insertionSort(testArray);
    // display after sorting
    displayArray(testArray);

    testArray = {5, 4, 3, 2, 1, -1};
    // display before sorting
    displayArray(testArray);
    // sort
    insertionSort(testArray);
    // display after sorting
    displayArray(testArray);

    return 0;
}