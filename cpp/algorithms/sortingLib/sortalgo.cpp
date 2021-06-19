//
// Created by Amith Kamath on 3/7/17.
//
#include "sortalgo.h"
#include "List.h"

namespace
{
    template <typename T> void swap(List<T>& inArr, unsigned long idx, unsigned long idy)
    {
        T temp = inArr.elementAt(idx);
        inArr.replaceAt(idx, inArr[idy]);
        inArr.replaceAt(idy, temp);
    }

    template <typename T> void merge(List<T>& outArray, List<T>& leftArray, List<T>& rightArray)
    {
        unsigned long leftSize = leftArray.size();
        unsigned long rightSize = rightArray.size();
        unsigned long outlen =  leftSize + rightSize;

        unsigned long leftIdx = 0;
        unsigned long rightIdx = 0;
        for(unsigned long idx = 0; idx < outlen; idx++)
        {
            if((leftIdx < leftSize) && (rightIdx < rightSize))
            {
                if(leftArray[leftIdx] <= rightArray[rightIdx])
                {
                    outArray.replaceAt(idx, leftArray[leftIdx]);
                    leftIdx++;
                }
                else
                {
                    outArray.replaceAt(idx, rightArray[rightIdx]);
                    rightIdx++;
                }
            }
            else if(rightIdx < rightSize)
            {
                outArray.replaceAt(idx, rightArray[rightIdx]);
                rightIdx++;
            }
            else if(leftIdx < leftSize)
            {
                outArray.replaceAt(idx, leftArray[leftIdx]);
                leftIdx++;
            }
        }
    }
}

namespace sortalgo
{

    template <typename T>
    void bubblesort(List<T>& inArray)
    {
        for(unsigned long idx = 0; idx < inArray.size(); idx++)
        {
            for(unsigned long inIdx = 0; inIdx < inArray.size()-1; inIdx++)
            {
                if(inArray[inIdx+1] < inArray[inIdx])
                {
                    swap(inArray, inIdx, inIdx+1);
                }
            }
        }
    }

    template <typename T>
    void insertionsort(List<T>& inArray)
    {
        // assume part of list is sorted.
        // go to next element, find where to insert this
        // move all elements after it
        unsigned long idx = 1;
        for(; idx < inArray.size(); idx++)
        {
            for(unsigned long cpidx = idx; cpidx > 0; cpidx--)
            {
                if(inArray[cpidx] < inArray[cpidx-1])
                {
                    swap(inArray, cpidx, cpidx-1);
                }
            }
        }
    }

    template <typename T>
    void mergesort(List<T>& inArray)
    {
        // divide the array into two parts
        unsigned long len = inArray.size();
        if(len > 2)
        {
            unsigned long mid;
            // setup the sub-arrays depending on length being even or odd.
            if(len%2 == 1)
                mid = (len+1)/2;
            else
                mid = len/2;
            List<T>* leftArray = inArray.subList(0, mid);
            List<T>* rightArray = inArray.subList(mid, len);

            // recursively call mergesort
            mergesort(*leftArray);
            mergesort(*rightArray);

            // merge once individual array is sorted
            merge(inArray, *leftArray, *rightArray);
        }
        else if(len == 2)
        {
            // handle base case
            if(inArray[0] > inArray[1])
            {
                swap(inArray, (unsigned long)0, (unsigned long)1);
            }
        }
        else
        {
            // single element. Don't do anything.
        }
    }

    // forward declaration for specific template types.
    template void bubblesort(List<int>&);
    template void insertionsort(List<int>&);
    template void mergesort(List<int>&);
}
