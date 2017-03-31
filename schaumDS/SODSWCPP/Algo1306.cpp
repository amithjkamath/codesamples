//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Algorithm 13.6 on page 258
//  The Heap Sort

template class T> void heapify(T* a, int k, int n)
{ T t = a[k];
  while (k < n/2)
  { int j = 2*k + 1;          // make j the oldest child of k
    if (j+1 < n && a[j] < a[j+1]) ++j;
    if (t > a[j]) break;
    a[k] = a[j];
    k = j;
  }
  a[k] = t;
}

template<class T> void sort(T* a, int n)
{ for (int i= n/2 - 1; i >=0; i--)
    heapify(a, i , n);
  for (int i = n-1; i > 0; i--)
  { swap(a[0], a[i]);
    // Invariant: the elements a[i:n-1] are in correct positions.
    heapify(a, 0 , i);
    // Invariant: the subarray a[0:i-1] has the heap property
  }
}
