#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void displayArray(std::vector<T> & inArray)
{
    if(inArray.size() == 0)
    {
        std::cout << "empty array" << std::endl;
    }
    else
    {
        for(unsigned long idx = 0; idx < inArray.size(); idx++)
            std::cout << inArray[idx] << " ";
        std::cout << std::endl;
    }
}

std::vector<int> subArray(std::vector<int> inArray, unsigned long low, unsigned long high)
{
    std::vector<int> outArray;
    for(unsigned long idx = low; idx < high; idx++)
    {
        outArray.push_back(inArray[idx]);
    }
    return outArray;
}

std::vector<int> merge(std::vector<int>& leftArray, std::vector<int>& rightArray)
{
    std::vector<int> outArray;
    unsigned long leftSize = leftArray.size();
    unsigned long rightSize = rightArray.size();
    unsigned long outlen =  leftSize + rightSize;

    unsigned long leftIdx = 0;
    unsigned long rightIdx = 0;
    for(unsigned long idx = 0; idx < outlen; idx++)
    {
        if(leftIdx < leftSize)
        {
            if(leftArray[leftIdx] <= rightArray[rightIdx])
            {
                outArray.push_back(leftArray[leftIdx]);
                leftIdx++;
            }
            else if(rightIdx < rightSize)
            {
                outArray.push_back(rightArray[rightIdx]);
                rightIdx++;
            }
            else
            {
                outArray.push_back(leftArray[leftIdx]);
                leftIdx++;
            }
        }
        else
        {
            if(rightIdx < rightSize)
            {
                outArray.push_back(rightArray[rightIdx]);
                rightIdx++;
            }
        }
    }

    return outArray;
}

void binarysort(std::vector<int>& inArray)
{
    // divide the array into two parts
    unsigned long len = inArray.size();
    unsigned long mid;
    if(len > 2)
    {
        // setup the sub-arrays depending on length being even or odd.
        if(len%2 == 1)
            mid = (len+1)/2;
        else
            mid = len/2;
        std::vector<int> leftArray = subArray(inArray, 0, mid);
        std::vector<int> rightArray = subArray(inArray, mid, len);

        // recursively call binarysort
        binarysort(leftArray);
        binarysort(rightArray);

        // merge once individual array is sorted
        inArray = merge(leftArray, rightArray);
    }
    else if(len == 2)
    {
        // handle base case
        if(inArray[0] > inArray[1])
        {
            // swap
            int temp = inArray[0];
            inArray[0] = inArray[1];
            inArray[1] = temp;
        }
    }
    else
    {
        // single element. Don't do anything.
    }
}

int main() {
    cout << __FILE__ << " compiled on " << __TIME__ << " and " << __DATE__ << endl;

    // odd sized array
    std::vector<int> aTestArray;

    aTestArray = {2, 1, 6, 3, 8, 4, 5, 9, 0};

    displayArray<int>(aTestArray);
    binarysort(aTestArray);
    displayArray<int>(aTestArray);

    // even sized array
    aTestArray = {2, 1, 6, 3, 8, 4};
    displayArray<int>(aTestArray);
    binarysort(aTestArray);
    displayArray<int>(aTestArray);

    // empty array
    aTestArray = {};
    displayArray<int>(aTestArray);
    binarysort(aTestArray);
    displayArray<int>(aTestArray);

    // one element array
    aTestArray = {1};
    displayArray<int>(aTestArray);
    binarysort(aTestArray);
    displayArray<int>(aTestArray);

    // two element array
    aTestArray = {5, 1};
    displayArray<int>(aTestArray);
    binarysort(aTestArray);
    displayArray<int>(aTestArray);
    return 0;
}