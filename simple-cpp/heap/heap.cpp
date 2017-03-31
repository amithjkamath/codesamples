//
// Created by Amith Kamath on 3/1/17.
//

#include "heap.h"

#include <iostream>

// Creation
//create-heap: create an empty heap
heap::heap()
{
    _parray = NULL;
    _length = 0;
}

//heapify: create a heap out of given array of elements
heap::heap(int* array, unsigned int size)
{
    _length = size;
    _parray = new int[size];
    for(int idx = 0; idx < size; idx++)
    {
        _parray[idx] = array[idx];
    }

    // build max heap
    for(int idx = _length/2; idx > 0; idx--)
        maxHeapify(idx);
}

//merge (union): joining two heaps to form a valid new heap containing all the elements of both, preserving the original heaps.
//meld: joining two heaps to form a valid new heap containing all the elements of both, destroying the original heaps.

// Operations
//find-max or find-min: find a maximum item of a max-heap, or a minimum item of a min-heap, respectively (a.k.a. peek)
int heap::max()
{
    if(_length > 0)
        return _parray[0];
    else
        return INT_MIN;
}

//insert: adding a new key to the heap (a.k.a., push[2])
void heap::insert(int position, int value)
{

}

//extract-min [or extract-max]: returns the node of minimum value from a min heap [or maximum value from a max heap] after removing it from the heap (a.k.a., pop[3])
int heap::extractMax()
{
    return 0;
}

//delete-max or delete-min: removing the root node of a max- or min-heap, respectively
// replace: pop root and push a new key. More efficient than pop followed by push, since only need to balance once, not twice, and appropriate for fixed-size heaps.[4]

void heap::printlinear()
{
    std::cout << "{ ";
    for(int idx = 0; idx < _length; idx++)
    {
        std::cout << _parray[idx] << ", ";
    }
    std::cout << "}" << std::endl;
}

//increase-key or decrease-key: updating a key within a max- or min-heap, respectively
void heap::increaseKey(int position, int key)
{

}

//delete: delete an arbitrary node (followed by moving last node and sifting to maintain heap)
//sift-up: move a node up in the tree, as long as needed; used to restore heap condition after insertion. Called "sift" because node moves up the tree until it reaches the correct level, as in a sieve.
//sift-down: move a node down in the tree, similar to sift-up; used to restore heap condition after deletion or replacement.

void swap(int* array, int pos1, int pos2)
{
    // assume pos1 and pos2 validity has been checked already
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void heap::maxHeapify(int position) // API assumes 1 index, not 0
{
    int currentIdx = position-1;
    if(position*2 > _length)
        return; //do nothing: in a leaf.

    int swapIdx = 0;
    if((position*2-1) < _length)
    {
        // has a left child
        swapIdx = position*2-1;
        if(_parray[swapIdx] > _parray[currentIdx])
        {
            swap(_parray, currentIdx, swapIdx);
            maxHeapify(swapIdx+1); // API assumes 1 index, not 0
        }
        if((position*2) < _length)
        {
            // also has a right child
            swapIdx = position*2;
            if(_parray[swapIdx] > _parray[currentIdx])
            {
                swap(_parray, currentIdx, swapIdx);
                maxHeapify(swapIdx+1); // API assumes 1 index, not 0
            }
        }
    }
}