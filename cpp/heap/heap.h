//
// Created by Amith Kamath on 3/1/17.
//

#ifndef HEAP_H
#define HEAP_H

// See operations here: https://en.wikipedia.org/wiki/Heap_(data_structure)#Operations

class heap
{
public:
    // Creation
    //create-heap: create an empty heap
    heap();
    //heapify: create a heap out of given array of elements
    //merge (union): joining two heaps to form a valid new heap containing all the elements of both, preserving the original heaps.
    //meld: joining two heaps to form a valid new heap containing all the elements of both, destroying the original heaps.
    heap(int*, unsigned int); // heapify an input array

    // Operations
    //find-max or find-min: find a maximum item of a max-heap, or a minimum item of a min-heap, respectively (a.k.a. peek)
    int max();
    //insert: adding a new key to the heap (a.k.a., push[2])
    void insert(int, int);
    //extract-min [or extract-max]: returns the node of minimum value from a min heap [or maximum value from a max heap] after removing it from the heap (a.k.a., pop[3])
    int extractMax();
    //delete-max or delete-min: removing the root node of a max- or min-heap, respectively
    // replace: pop root and push a new key. More efficient than pop followed by push, since only need to balance once, not twice, and appropriate for fixed-size heaps.[4]

    void printlinear();

private:
    //increase-key or decrease-key: updating a key within a max- or min-heap, respectively
    void increaseKey(int, int);
    //delete: delete an arbitrary node (followed by moving last node and sifting to maintain heap)
    //sift-up: move a node up in the tree, as long as needed; used to restore heap condition after insertion. Called "sift" because node moves up the tree until it reaches the correct level, as in a sieve.
    //sift-down: move a node down in the tree, similar to sift-up; used to restore heap condition after deletion or replacement.

    void maxHeapify(int);
// properties
public:

private:
    int* _parray;
    int _length;
};


#endif //HEAP_H
